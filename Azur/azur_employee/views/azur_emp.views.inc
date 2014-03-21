<?php

/**
 * Implements hook_views_data();
 */
function azur_emp_views_data() {
  $data = array();
  employee_views_data($data);
  employee_address_views_data($data);
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
	
  $data['employee']['uid'] = array(
    'title' => t('Employee Uid.'),
    'help' => t('Employee Uid.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort', ),
    'relationship' => array(
      'title' => t('Employee User Record'),
      'help' => t('Employee User Record'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
      'field' => 'uid',
      'label' => t('Employee User Record'),
    ),
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
  // $data['employee']['department'] = array(
    // 'title' => t('Department'),
    // 'help' => t('Department'),
    // 'field' => array(
      // 'handler' => 'views_handler_field',
      // 'click sortable' => TRUE,
    // ),
    // 'filter' => array('handler' => 'views_handler_filter_numeric', ),
    // 'sort' => array('handler' => 'views_handler_sort', ),
  // );
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
   $data['employee']['sdate'] = array(
    'title' => t('Start Date'),
    'help' => t('Sdate'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );

}

/**
 * Views data definition for table dcemployee_clinics
 */
function employee_address_views_data(&$data) {
  $data['address']['table']['group'] = t('Employee Address');
  $data['address']['table']['join']['employee'] = array(
    'left_field' => 'eid',
    'field' => 'eid',
    'type' => 'INNER',
  );
  $data['address']['eid'] = array(
    'title' => t('Employee Id.'),
    'help' => t('Employee Id.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort', ),
    'relationship' => array(
      'title' => t('Employee '),
      'help' => t('Employee Record'),
      'handler' => 'views_handler_relationship',
      'base' => 'employee',
      'base field' => 'eid',
      'field' => 'eid',
      'label' => t('Employee'),
    ),
  );
  $data['address']['aid'] = array(
    'title' => t('Address ID'),
    'help' => t('Address ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort_group_by_numeric', ),
    'argument' => array('handler' => 'views_handler_argument_numeric', ),
    'title' => t('address id'),
    'help' => t(''),
  );
  $data['address']['emp_address'] = array(
    'title' => t('Address'),
    'help' => t('address'),
    'field' => array(
     'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['address']['city'] = array(
    'title' => t('City'),
    'help' => t('city'),
    'field' => array(
      'handler' => 'views_handler_field_country_taxonomy',
      'click sortable' => TRUE,
    ),

    'sort' => array('handler' => 'views_handler_sort', ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'argument' => array('handler' => 'views_handler_argument_string', ),
  );
  $data['address']['state'] = array(
    'title' => t('State'),
    'help' => t('state'),
    'field' => array(
     'handler' => 'views_handler_field_country_taxonomy',
      'click sortable' => TRUE,
    ),

    'sort' => array('handler' => 'views_handler_sort', ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'argument' => array('handler' => 'views_handler_argument_string', ),
  );
  $data['address']['country'] = array(
    'title' => t('Country'),
    'help' => t('country'),
    'field' => array(
      'handler' => 'views_handler_field_country_taxonomy',
      'click sortable' => TRUE,
    ),

    'sort' => array('handler' => 'views_handler_sort', ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'argument' => array('handler' => 'views_handler_argument_string', ),
  );
  $data['address']['pincode'] = array(
    'title' => t('Pincode'),
    'help' => t('pincode'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['address']['phone'] = array(
    'title' => t('Mobile'),
    'help' => t('mobile'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['address']['resphone'] = array(
    'title' => t('Resphone'),
    'help' => t('resphone'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
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
      'views_handler_field_country_taxonomy'=> array(
        'parent' => 'views_handler_field',
      ),
       )
  );
}
      