<?php
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of fieldinsync import class for importing RSPs into the database
 *
 * @author arvind
 */
class fieldinsync_import_processor extends FeedsProcessor {

  /**
   * Delete a series of entities.
   *
   * @param $entity_ids
   *   Array of unique identity ids to be deleted.
   */
  protected function entityDeleteMultiple($entity_ids) {
    db_truncate('employee')->execute();
    variable_set('employee_import_has_data', FALSE);
  }

  /**
   * Dummy override. Does nothing.
   */
  protected function entityLoad(FeedsSource $source, $entity_id) {
    //    dpm($source);
    //    dpm($entity_id);
  }

  /**
   * Dummy override. Does nothing.
   */
  protected function entitySave($entity) {
    //    dpm($entity);
  }

  /**
   * Dummy override. Does nothing.
   */
  protected function newEntity(FeedsSource $source) {
    //    dpm($source);
  }

  /**
   * Entity type this processor (supposedly) operates on. Not used in actual processing.
   */
  public function entityType() {
    return 'user';
  }

  /**
   * Process the result of the parsing stage.
   *
   * @param FeedsSource $source
   *   Source information about this import.
   * @param FeedsParserResult $parser_result
   *   The result of the parsing stage.
   */
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    //1.get item from parser result
    //2.validate all the fields in the csv
    global $user;
    $mob_arry;
    $err_msg;
    $tax_exists;
    $cid = 'fieldinsync' . $user->uid;
    $tax_insert;
    $cahe = (cache_get($cid));
    if (isset($cahe)) {
      $count = $cahe->data;
    }
    else {
      $count = 0;
    }
    $y = $count;
    $errors_array;
    $tax_values;
    $taxitem;
    $error_rows = array();
    $counter = 0;
    $vald;
    foreach ($parser_result->items as $value) {
      foreach ($value as $key => $item) {
        $vald [$key] = trim($item);
      }
      if (!(is_numeric($vald['phone']))) {
        $errors_array['phone'][] = $count;
      }
      if (strcmp($vald['level'], 'silver') && strcmp($vald['level'], 'gold')) {
        $errors_array['level'][] = $count;
      }
      if (strcmp($vald['status'], 'active') && strcmp($vald['status'], 'blocked')) {
        $errors_array['status'][] = $count;
      }
      $tax_values[$vald['zone']] = strtolower($vald['zone']);
      $tax_values[$vald['city']] = strtolower($vald['city']);
      $tax_values[$vald['retailer']] = strtolower($vald['retailer']);
      $tax_values[$vald['retailertype']] = strtolower($vald['retailertype']);
      $mob_arry[] = $vald['phone'];
      $taxitem[$vald['zone']][] = $count;
      $taxitem[$vald['city']][] = $count;
      $taxitem[$vald['retailer']][] = $count;
      $taxitem[$vald['retailertype']][] = $count;
      $count++;
    }
    $cnt = $count;
    $query = db_select('taxonomy_term_data', 'tax')->fields('tax', array(
      'name',
      'tid'
    ))->condition('name', $tax_values, 'IN');
    $query->addExpression('LOWER(name)', 'ne2');
    $result = $query->execute();
    foreach ($result as $taxo) {
      $tax_exists[$taxo->ne2] = $taxo->tid;
    }
    foreach ($taxitem as $tx => $val) {
      foreach ($val as $key) {
        if (isset($tax_exists[strtolower($tx)])) {
          $tax_insert[strtolower($tx)] = $tax_exists[strtolower($tx)];
        }
        else {
          $errors_array[$tx][] = $key;
        }
      }
    }
    $err_msg['phone'] = t('The phone number is not numeric in');
    $err_msg['level'] = t('The level can be siler or gold only');
    $err_msg['status'] = t('The status of the Rsp can be active or blocked');
    $list;
    if (isset($errors_array)) {
      foreach ($errors_array as $key => $value) {
        foreach ($value as $x) {
          if (isset($err_msg[$key])) {
            $list[] = "Row :" . $x . "  " . $err_msg[$key];
          }
          else {
            $list[] = "Row :" . $x . "  " . $key . "    Is not a valid field";
          }
          $error_rows[$x - $y] = $x - $y;
        }
      }
    }
    $variables = array('items' => $list);
    $content = theme('item_list', $variables);
    $uprec;
    //3.check if the field already exists
    $squery = db_select('fieldinsync_rsp', 'frsp')->fields('frsp', array(
      'rsp_mobile',
      'rsp_id'
    ))->condition('frsp.rsp_mobile', $mob_arry, 'IN');
    $uprec = $squery->execute()->fetchAllKeyed();
    $iquery = db_insert('fieldinsync_rsp')->fields(array(
      'rsp_name',
      'rsp_mobile',
      'rsp_level',
      'rsp_status',
      'rsp_zone',
      'rsp_city',
      'rsp_retailer',
      'rsp_retailertype',
      'rsp_email'
    ));
    //4. If yes update the field 
    $value;
    foreach ($parser_result->items as $pars_item => $val) {
      foreach ($val as $key => $untrim_val) {
        $value[$key] = trim($untrim_val);
      }
      $account = new stdClass();
      $account->is_new = TRUE;
      if (isset($uprec[$value['phone']]) && !isset($error_rows[$pars_item])) {
        $uquery = db_update('fieldinsync_rsp')->fields(array(
          'rsp_name' => $value['name'],
          'rsp_mobile' => $value['phone'],
          'rsp_level' => $value['level'],
          'rsp_status' => $value['status'],
          'rsp_zone' => $tax_insert[strtolower($value['zone'])],
          'rsp_city' => $tax_insert[strtolower($value['city'])],
          'rsp_retailer' => $tax_insert[strtolower($value['retailer'])],
          'rsp_retailertype' => $tax_insert[strtolower($value['retailertype'])],
          'rsp_email' => $value['email'],
        ));
        $uquery->condition('rsp_id', $uprec[$value['phone']], '=');
        $uquery->execute();
      }
      //5.Else insert the field
      else {

        if (!isset($error_rows[$pars_item]) && !isset($uprec[$updt['phone']])) {
          $values = array(
            'rsp_name' => $value['name'],
            'rsp_mobile' => $value['phone'],
            'rsp_level' => $value['level'],
            'rsp_status' => $value['status'],
            'rsp_zone' => $tax_insert[strtolower($value['zone'])],
            'rsp_city' => $tax_insert[strtolower($value['city'])],
            'rsp_retailer' => $tax_insert[strtolower($value['retailer'])],
            'rsp_retailertype' => $tax_insert[strtolower($value['retailertype'])],
            'rsp_email' => $value['email'],
          );
          $iquery->values($values);
          $name;
          $pos = strpos($value['name'], ' ');
          if (isset($pos)) {
            $name = substr($value['name'], 0, $pos);
          }
          else {
            $name = $value['name'];
          }
          $name = strtolower($name);
          $user_vars = array(
            'name' => $value['email'],
            'pass' => $value['phone'],
            'mail' => $value['email'],
            'status' => 1,
            'time_zone' => $user->timezone
          );
          $category = 'account';
          user_save($account, $user_vars, $category);
        }
      }
    }
    $iquery->execute();
    $selquery = db_select('fieldinsync_rsp', 'frsp');
    $selquery->innerJoin('users', 'u', 'frsp.rsp_email = u.name');
    $selquery->isNull('frsp.uid');
    $selquery->fields('frsp', array('rsp_id'));
    $selquery->fields('u', array('uid'));
    $res = $selquery->execute()->fetchAllKeyed();
    foreach ($res as $key => $val) {
      db_update('fieldinsync_rsp')->fields(array('uid' => $val))->condition('rsp_id', $key, '=')->execute();
    }
    cache_set($cid, $count, 'cache', CACHE_TEMPORARY);
    $cahe = (cache_get($cid));
    if ($source->progressImporting() == FEEDS_BATCH_COMPLETE) {
      drupal_flush_all_caches();
    }
    if (isset($list)) {
      drupal_set_message($content, 'error');
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    return array();
  }

  /**
   * Overrides parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);

    return $form;
  }

  /**
   * Declare default configuration.
   */
  public function configDefaults() {
    $config_defaults = parent::configDefaults();
    $config_defaults['date_format'] = NULL;
    return $config_defaults;
  }

  /**
   * Counts the number of items imported by this processor.
   */
  public function itemCount(FeedsSource $source) {
    return db_query("SELECT count(rsp_id) FROM {fieldinsync_rsp}")->fetchField();
  }

}

