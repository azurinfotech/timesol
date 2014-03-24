<?php

/**
 * Implements hook_views_data();
 */
function timesol_views_data() {
  $data = array();
  timesolution_views_data($data);
  return $data;
}


function timesolution_views_data(&$data){
  $data['empclkin']['table']['group'] = t('Employee ClockIn time');
  $data['empclkin']['table']['base'] = array(
    'field' => 'cid',
    'title' => t('ClockIn'),
    'help' => t(''),
  );
  
  $data['empclkin']['cid'] = array(
    'title' => t('Employee ClockIn ID'),
    'help' => t('Employee ClockIn ID'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort_group_by_numeric', ),
    'argument' => array('handler' => 'views_handler_argument_numeric', ),
    'title' => t('employee clockIn id'),
    'help' => t(''),
  );
  $data['empclkin']['eid'] = array(
    'title' => t('Employee id.'),
    'help' => t('Employee id.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array('handler' => 'views_handler_argument_numeric', ),
    'title' => t('employee id'),
    'help' => t(''),
	'sort' => array('handler' => 'views_handler_sort', ),
    'relationship' => array(
      'title' => t('Employee ID'),
      'help' => t('Employee User Record'),
      'handler' => 'views_handler_relationship',
      'base' => 'employee',
      'base field' => 'eid',
      'field' => 'eid',
      'label' => t('Employee ID'),
    ),
  );
  $data['empclkin']['flag'] = array(
    'title' => t('Flag'),
    'help' => t('Flag'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_numeric', ),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  $data['empclkin']['clkin'] = array(
    'title' => t('ClockIn'),
    'help' => t('Sdate'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' =>array('handler' => 'views_handler_filter_date'),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
	$data['empclkin']['clkin_filter'] = array(
    'title' => t('Using the clkin as a filter.'),
    'help' => t('Clock in filter'),
    'real field' => 'clkin',
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array('handler' => 'views_handler_filter_date', ),
    'sort' => array('handler' => 'views_handler_sort_date'),
    'argument' => array('handler' => 'views_handler_argument_date', ),
  );
  $data['empclkin']['clkout'] = array(
    'title' => t('ClockOut'),
    'help' => t('Sdate'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' =>array('handler' => 'views_handler_filter_date'),
    'sort' => array('handler' => 'views_handler_sort', ),
  );
  
}