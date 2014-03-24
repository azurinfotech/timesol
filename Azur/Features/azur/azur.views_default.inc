<?php
/**
 * @file
 * azur.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function azur_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'employee';
  $view->human_name = 'Details';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Details';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Employee: Employee User Record */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'employee';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Employee: Firstname */
  $handler->display->display_options['fields']['firstname']['id'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['table'] = 'employee';
  $handler->display->display_options['fields']['firstname']['field'] = 'firstname';
  /* Field: Employee: Lastname */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'employee';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  /* Field: Employee: Qualification */
  $handler->display->display_options['fields']['qualification']['id'] = 'qualification';
  $handler->display->display_options['fields']['qualification']['table'] = 'employee';
  $handler->display->display_options['fields']['qualification']['field'] = 'qualification';
  /* Field: Employee: Start Date */
  $handler->display->display_options['fields']['sdate']['id'] = 'sdate';
  $handler->display->display_options['fields']['sdate']['table'] = 'employee';
  $handler->display->display_options['fields']['sdate']['field'] = 'sdate';
  $handler->display->display_options['fields']['sdate']['date_format'] = 'short';
  /* Field: Employee: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'employee';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['static_value_type'] = '1';
  /* Field: Employee Address: Mobile */
  $handler->display->display_options['fields']['phone']['id'] = 'phone';
  $handler->display->display_options['fields']['phone']['table'] = 'address';
  $handler->display->display_options['fields']['phone']['field'] = 'phone';
  /* Field: Employee Address: Resphone */
  $handler->display->display_options['fields']['resphone']['id'] = 'resphone';
  $handler->display->display_options['fields']['resphone']['table'] = 'address';
  $handler->display->display_options['fields']['resphone']['field'] = 'resphone';
  /* Field: Employee Address: Address */
  $handler->display->display_options['fields']['emp_address']['id'] = 'emp_address';
  $handler->display->display_options['fields']['emp_address']['table'] = 'address';
  $handler->display->display_options['fields']['emp_address']['field'] = 'emp_address';
  /* Field: Employee Address: Pincode */
  $handler->display->display_options['fields']['pincode']['id'] = 'pincode';
  $handler->display->display_options['fields']['pincode']['table'] = 'address';
  $handler->display->display_options['fields']['pincode']['field'] = 'pincode';
  /* Field: Employee Address: City */
  $handler->display->display_options['fields']['city']['id'] = 'city';
  $handler->display->display_options['fields']['city']['table'] = 'address';
  $handler->display->display_options['fields']['city']['field'] = 'city';
  /* Field: Employee Address: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'address';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Employee Address: Country */
  $handler->display->display_options['fields']['country']['id'] = 'country';
  $handler->display->display_options['fields']['country']['table'] = 'address';
  $handler->display->display_options['fields']['country']['field'] = 'country';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/pdetails';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Personal details';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['details'] = $view;

  $view = new view();
  $view->name = 'employee_clock_in';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'empClkIn';
  $view->human_name = 'Employee clock-in';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Employee clock-in';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'clkin' => 'clkin',
    'clkout' => 'clkout',
    'php' => 'php',
    'expression' => 'expression',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'clkin' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clkout' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['label'] = 'Total Time';
  $handler->display->display_options['footer']['php']['php_output'] = '<?php 
$total_time = 0;
foreach($results as $row){
$total_time += ($row ->empclkin_clkout - $row->empclkin_clkin);
}
$total_time = $total_time/3600;
echo t(\'Total Time: \').$total_time.t(\' hrs\');
?>';
  /* Relationship: Employee ClockIn time: Employee ID */
  $handler->display->display_options['relationships']['eid']['id'] = 'eid';
  $handler->display->display_options['relationships']['eid']['table'] = 'empClkIn';
  $handler->display->display_options['relationships']['eid']['field'] = 'eid';
  /* Field: Employee: Firstname */
  $handler->display->display_options['fields']['firstname']['id'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['table'] = 'employee';
  $handler->display->display_options['fields']['firstname']['field'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['relationship'] = 'eid';
  /* Field: Employee: Lastname */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'employee';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['relationship'] = 'eid';
  /* Field: Employee: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'employee';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'eid';
  $handler->display->display_options['fields']['type']['static_value_type'] = '1';
  /* Field: Employee ClockIn time: ClockIn */
  $handler->display->display_options['fields']['clkin']['id'] = 'clkin';
  $handler->display->display_options['fields']['clkin']['table'] = 'empClkIn';
  $handler->display->display_options['fields']['clkin']['field'] = 'clkin';
  $handler->display->display_options['fields']['clkin']['exclude'] = TRUE;
  /* Field: Employee ClockIn time: ClockOut */
  $handler->display->display_options['fields']['clkout']['id'] = 'clkout';
  $handler->display->display_options['fields']['clkout']['table'] = 'empClkIn';
  $handler->display->display_options['fields']['clkout']['field'] = 'clkout';
  $handler->display->display_options['fields']['clkout']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Date';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo date(\'d/m/y\',$row -> clkin);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['label'] = 'Time';
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['expression'] = '([clkout]-[clkin])/3600';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Clock In';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
echo date(\'H:i\',$row ->clkin);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Clock out';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php 
echo date(\'H:i\',$row -> clkout);
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Contextual filter: Employee ClockIn time: employee id */
  $handler->display->display_options['arguments']['eid']['id'] = 'eid';
  $handler->display->display_options['arguments']['eid']['table'] = 'empClkIn';
  $handler->display->display_options['arguments']['eid']['field'] = 'eid';
  $handler->display->display_options['arguments']['eid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['eid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['eid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['eid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['eid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['eid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Employee ClockIn time: Using the clkin as a filter. */
  $handler->display->display_options['filters']['clkin_filter']['id'] = 'clkin_filter';
  $handler->display->display_options['filters']['clkin_filter']['table'] = 'empClkIn';
  $handler->display->display_options['filters']['clkin_filter']['field'] = 'clkin_filter';
  $handler->display->display_options['filters']['clkin_filter']['operator'] = '>';
  $handler->display->display_options['filters']['clkin_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['clkin_filter']['expose']['operator_id'] = 'clkin_filter_op';
  $handler->display->display_options['filters']['clkin_filter']['expose']['label'] = 'Filter';
  $handler->display->display_options['filters']['clkin_filter']['expose']['description'] = 'Enter the date from which you want the summary(format :YYYY/MM/DD)';
  $handler->display->display_options['filters']['clkin_filter']['expose']['operator'] = 'clkin_filter_op';
  $handler->display->display_options['filters']['clkin_filter']['expose']['identifier'] = 'clkin_filter';
  $handler->display->display_options['filters']['clkin_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'clkin_summary/%';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'clkin_summary/download';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['employee_clock_in'] = $view;

  $view = new view();
  $view->name = 'list_of_employees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'employee';
  $view->human_name = 'List of Employees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List of Employees';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'eid' => 'eid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'eid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Employee: Firstname */
  $handler->display->display_options['fields']['firstname']['id'] = 'firstname';
  $handler->display->display_options['fields']['firstname']['table'] = 'employee';
  $handler->display->display_options['fields']['firstname']['field'] = 'firstname';
  /* Field: Employee: Lastname */
  $handler->display->display_options['fields']['lastname']['id'] = 'lastname';
  $handler->display->display_options['fields']['lastname']['table'] = 'employee';
  $handler->display->display_options['fields']['lastname']['field'] = 'lastname';
  /* Field: Employee: Qualification */
  $handler->display->display_options['fields']['qualification']['id'] = 'qualification';
  $handler->display->display_options['fields']['qualification']['table'] = 'employee';
  $handler->display->display_options['fields']['qualification']['field'] = 'qualification';
  /* Field: Employee: Start Date */
  $handler->display->display_options['fields']['sdate']['id'] = 'sdate';
  $handler->display->display_options['fields']['sdate']['table'] = 'employee';
  $handler->display->display_options['fields']['sdate']['field'] = 'sdate';
  $handler->display->display_options['fields']['sdate']['date_format'] = 'long';
  /* Field: Employee: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'employee';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['static_value_type'] = '1';
  /* Field: Employee: employee id */
  $handler->display->display_options['fields']['eid']['id'] = 'eid';
  $handler->display->display_options['fields']['eid']['table'] = 'employee';
  $handler->display->display_options['fields']['eid']['field'] = 'eid';
  $handler->display->display_options['fields']['eid']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Clock In summary';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$path = l(\'View Clock In summary\',\'clkin_summary/\'.$row ->eid);
echo $path;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'View details';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
$path = l(\'View Details\',\'user/\'.$row ->eid.\'/pdetails\');
echo $path;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'employees/list';
  $export['list_of_employees'] = $view;

  $view = new view();
  $view->name = 'request_details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'request';
  $view->human_name = 'Request details';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Request details';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'adid' => 'adid',
    'rstatus' => 'rstatus',
    'sdate' => 'sdate',
    'edate' => 'edate',
    'descp' => 'descp',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'adid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rstatus' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sdate' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edate' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'descp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Request: Employee request Record */
  $handler->display->display_options['relationships']['eid']['id'] = 'eid';
  $handler->display->display_options['relationships']['eid']['table'] = 'request';
  $handler->display->display_options['relationships']['eid']['field'] = 'eid';
  /* Relationship: Employee: Employee User Record */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'employee';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'eid';
  /* Field: Request: Assigned to */
  $handler->display->display_options['fields']['adid']['id'] = 'adid';
  $handler->display->display_options['fields']['adid']['table'] = 'request';
  $handler->display->display_options['fields']['adid']['field'] = 'adid';
  $handler->display->display_options['fields']['adid']['static_value_type'] = '3';
  /* Field: Request: Request status */
  $handler->display->display_options['fields']['rstatus']['id'] = 'rstatus';
  $handler->display->display_options['fields']['rstatus']['table'] = 'request';
  $handler->display->display_options['fields']['rstatus']['field'] = 'rstatus';
  $handler->display->display_options['fields']['rstatus']['static_value_type'] = '2';
  /* Field: Request: Start Date */
  $handler->display->display_options['fields']['sdate']['id'] = 'sdate';
  $handler->display->display_options['fields']['sdate']['table'] = 'request';
  $handler->display->display_options['fields']['sdate']['field'] = 'sdate';
  $handler->display->display_options['fields']['sdate']['date_format'] = 'long';
  /* Field: Request: Request description */
  $handler->display->display_options['fields']['descp']['id'] = 'descp';
  $handler->display->display_options['fields']['descp']['table'] = 'request';
  $handler->display->display_options['fields']['descp']['field'] = 'descp';
  $handler->display->display_options['fields']['descp']['label'] = 'Description';
  /* Contextual filter: Request: Assigned to */
  $handler->display->display_options['arguments']['adid']['id'] = 'adid';
  $handler->display->display_options['arguments']['adid']['table'] = 'request';
  $handler->display->display_options['arguments']['adid']['field'] = 'adid';
  $handler->display->display_options['arguments']['adid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['adid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['adid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['adid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['adid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['adid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Request: Request ID */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'request';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  /* Field: Request: Employee Id */
  $handler->display->display_options['fields']['eid']['id'] = 'eid';
  $handler->display->display_options['fields']['eid']['table'] = 'request';
  $handler->display->display_options['fields']['eid']['field'] = 'eid';
  $handler->display->display_options['fields']['eid']['label'] = 'From';
  $handler->display->display_options['fields']['eid']['static_value_type'] = '3';
  /* Field: Request: Request status */
  $handler->display->display_options['fields']['rstatus']['id'] = 'rstatus';
  $handler->display->display_options['fields']['rstatus']['table'] = 'request';
  $handler->display->display_options['fields']['rstatus']['field'] = 'rstatus';
  $handler->display->display_options['fields']['rstatus']['static_value_type'] = '2';
  /* Field: Request: Start Date */
  $handler->display->display_options['fields']['sdate']['id'] = 'sdate';
  $handler->display->display_options['fields']['sdate']['table'] = 'request';
  $handler->display->display_options['fields']['sdate']['field'] = 'sdate';
  $handler->display->display_options['fields']['sdate']['date_format'] = 'long';
  /* Field: Request: Request description */
  $handler->display->display_options['fields']['descp']['id'] = 'descp';
  $handler->display->display_options['fields']['descp']['table'] = 'request';
  $handler->display->display_options['fields']['descp']['field'] = 'descp';
  $handler->display->display_options['fields']['descp']['label'] = 'Description';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Approve';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$path = l(\'Approve\',\'approve/\'.$row ->rid.\'/requests\');
echo $path;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Reject';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
$path = l(\'Reject\',\'reject/\'.$row ->rid.\'/request\');
echo $path;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['path'] = 'assignedto/%/requests';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Your Requests';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Requests';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Request: Employee Id */
  $handler->display->display_options['arguments']['eid']['id'] = 'eid';
  $handler->display->display_options['arguments']['eid']['table'] = 'request';
  $handler->display->display_options['arguments']['eid']['field'] = 'eid';
  $handler->display->display_options['arguments']['eid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['eid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['eid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['eid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['eid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['eid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'your/%/requests';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Assigned to you';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'request_your/download';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'page_1' => 0,
  );

  /* Display: Data export 2 */
  $handler = $view->new_display('views_data_export', 'Data export 2', 'views_data_export_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'request-assignedto/download';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page' => 0,
  );
  $export['request_details'] = $view;

  return $export;
}
