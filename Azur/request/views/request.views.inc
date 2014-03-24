<?php

/**
 * Implements hook_views_data();
 */
function request_views_data() {
  $data = array();
  _request_views_data($data);
  return $data;
}

function _request_views_data(&$data) {
  	
  $data['request']['table']['group'] = t('Request');
  $data['request']['table']['base'] = array(
    'field' => 'rid',
    'title' => t('Request'),
    'help' => t(''),
  );
  $data['request']['rid'] = array(
    'title' => t('Request ID'),
    'help' => t('Request ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort_group_by_numeric', ),
  );
	
  $data['request']['eid'] = array(
    'title' => t('Employee id.'),
    'help' => t('Employee id.'),
    'field' => array(
      'handler' => 'views_handler_field_azur_static',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort', ),
    'relationship' => array(
      'title' => t('Employee request Record'),
      'help' => t('Employee request Record'),
      'handler' => 'views_handler_relationship',
      'base' => 'employee',
      'base field' => 'eid',
      'field' => 'eid',
      'label' => t('Employee request Record'),
    ),
    'argument' => array('handler' => 'views_handler_argument_numeric', ),
    'title' => t('Employee Id'),
    'help' => t(''),
  );
  $data['request']['adid'] = array(
    'title' => t('Admin ID'),
    'help' => t('Admin ID'),
    'field' => array(
      'handler' => 'views_handler_field_azur_static',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
    'argument' => array('handler' => 'views_handler_argument_numeric', ),
    'title' => t('Assigned to'),
    'help' => t(''),
  );
 $data['request']['fid'] = array(
    'title' => t('File ID'),
    'help' => t('File ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['request']['rstatus'] = array(
    'title' => t('Request status'),
    'help' => t('Request status'),
    'field' => array(
      'handler' => 'views_handler_field_azur_static',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  ); 
  $data['request']['sdate'] = array(
    'title' => t('Start Date'),
    'help' => t('Sdate'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['request']['descp'] = array(
    'title' => t('Request description'),
    'help' => t('Request description'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_string', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['request']['edate'] = array(
    'title' => t('End Date'),
    'help' => t('edate'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['request']['rtype'] = array(
    'title' => t('Type'),
    'help' => t('type'),
    'field' => array(
      'handler' => 'views_handler_field_azur_static',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
}