<?php

 function bid_management_views_data() {
 $data = array();
 bid_managements_data($data); 
 return $data;
 }
 
/**
 * Views data definition for table bid_management
 */
function bid_managements_data(&$data) {
  $data['bid_management']['table']['group']  = t('bid_management_group');
  $data['bid_management']['table']['base'] = array(
    'field' => 'bid',
    'title' => t('bid_management'),
    'help' => t(''),
  );
  $data['bid_management']['bid'] = array(
    'title' => t('This Is The Primary Key Of The Table'),
    'help' => t('This Is The Primary Key Of The Table'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_group_by_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_group_by_numeric',
      'name field' => 'This is the primary key of the table',
      'numeric' => TRUE,
    ),
  );
  $data['bid_management']['prosp_name'] = array(
    'title' => t('Name Of The Prospect'),
    'help' => t('Name Of The Prospect'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name field' => 'name of the prospect',
    ),
  );
  $data['bid_management']['opp_desc'] = array(
    'title' => t('Oppurtunity Description'),
    'help' => t('Oppurtunity Description'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name field' => 'Oppurtunity Description',
    ),
  );
  $data['bid_management']['value'] = array(
    'title' => t('Money Value'),
    'help' => t('Money Value'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name field' => 'Money value',
    ),
  );
  $data['bid_management']['horizontal'] = array(
    'title' => t('Horizontal'),
    'help' => t('Horizontal'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_group_by_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_group_by_numeric',
      'name field' => 'horizontal',
      'numeric' => TRUE,
    ),
  );
  $data['bid_management']['sel_criteria'] = array(
    'title' => t('Selection Criteria'),
    'help' => t('Selection Criteria'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name field' => 'selection criteria',
    ),
  );
  $data['bid_management']['competition'] = array(
    'title' => t('Competition'),
    'help' => t('Competition'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name field' => 'competition',
    ),
  );
  $data['bid_management']['opp_iss_date'] = array(
    'title' => t('Oppurtunity Issue Date'),
    'help' => t('Oppurtunity Issue Date'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_group_by_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_group_by_numeric',
      'name field' => 'oppurtunity issue date',
      'numeric' => TRUE,
    ),
  );
  $data['bid_management']['resp_due_date'] = array(
    'title' => t('Response Due Date'),
    'help' => t('Response Due Date'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_group_by_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_group_by_numeric',
      'name field' => 'response due date',
      'numeric' => TRUE,
    ),
  );
  $data['bid_management']['sales_owner'] = array(
    'title' => t('Sales Owner'),
    'help' => t('Sales Owner'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_group_by_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_group_by_numeric',
      'name field' => 'sales owner',
      'numeric' => TRUE,
    ),
  );
  $data['bid_management']['delivery_bid_owner'] = array(
    'title' => t('Delivery Bid Owner'),
    'help' => t('Delivery Bid Owner'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_group_by_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_group_by_numeric',
      'name field' => 'delivery bid owner',
      'numeric' => TRUE,
    ),
  );
  $data['bid_management']['win_the'] = array(
    'title' => t('Win Themes'),
    'help' => t('Win Themes'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name field' => 'win themes',
    ),
  );
  $data['bid_management']['core_team'] = array(
    'title' => t('Core_team'),
    'help' => t('Core_team'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
      'name field' => 'core_team',
    ),
  );
}