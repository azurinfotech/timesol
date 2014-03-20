<?php

/**
 * Implements hook_views_data();
 */
function azur_emp_views_data() {
  $data = array();
  employee_views_data($data);
  return $data;
}

function employee_views_data(&$data) {
  $data['employee']['table']['group'] = t('Employee');
  $data['employee']['table']['base'] = array(
    'field' => 'eid',
    'title' => t('Employee'),
    'help' => t(''),
  );
  $data['employee']['eid'] = array(
    'title' => t('Employee ID'),
    'help' => t('Employee ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort_group_by_numeric', ),
    'argument' => array('handler' => 'views_handler_argument_numeric', ),
    'title' => t('employee id'),
    'help' => t(''),
  );
	
  $data['employee']['table']['join']['users'] = array(
    'left_field' => 'uid',
    'field' => 'uid',
    'type' => 'INNER',
  );
  
  $data['employee']['table']['join']['address'] = array(
    'left_field' => 'eid',
    'field' => 'eid',
    'type' => 'INNER',
  );

  $data['employee']['firstname'] = array(
    'title' => t('Firstname'),
    'help' => t('Firstname'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['employee']['lastname'] = array(
    'title' => t('Lastname'),
    'help' => t('Lastname'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['employee']['type'] = array(
    'title' => t('Type'),
    'help' => t('type'),
    'field' => array(
      'handler' => 'views_handler_field_azur_static',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['employee']['enum'] = array(
    'title' => t('Employee Number'),
    'help' => t('Employee Number'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['employee']['uid'] = array(
    'title' => t('Employee UID'),
    'help' => t('Employee UID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_user_current', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['employee']['department'] = array(
    'title' => t('Department'),
    'help' => t('Department'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['employee']['qualification'] = array(
    'title' => t('Qualification'),
    'help' => t('qualification'),
    'field' => array(
     'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );

}
/**
 * Implements hook_views_handlers
 */
function azur_emp_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'azur_emp') . '/views',
    ),
    'handlers' => array(
      'views_handler_field_azur_static' => array(
        'parent' => 'views_handler_field',
      ),
       )
  );
}
      