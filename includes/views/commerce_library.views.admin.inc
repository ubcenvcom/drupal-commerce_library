<?php
$view = new view();
$view->name = 'commerce_loan_admin_view';
$view->description = 'Administrator loans view';
$view->tag = 'commerce';
$view->base_table = 'commerce_library_loan';
$view->human_name = 'Commerce Loans';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Returns';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view any commerce_order entity';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'loan_id' => 'loan_id',
  'order_id' => 'order_id',
  'sku' => 'sku',
  'amount' => 'amount',
  'status' => 'status',
  'due' => 'due',
  'fullfilled' => 'fullfilled',
  'name' => 'name',
  'product_id' => 'product_id',
);
$handler->display->display_options['style_options']['class'] = '';
$handler->display->display_options['style_options']['default'] = 'loan_id';
$handler->display->display_options['style_options']['info'] = array(
  'loan_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'sku' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'amount' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'status' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'due' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'fullfilled' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'product_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Header: Global: Result summary */
$handler->display->display_options['header']['result']['id'] = 'result';
$handler->display->display_options['header']['result']['table'] = 'views';
$handler->display->display_options['header']['result']['field'] = 'result';
/* Relationship: Commerce Loan: Order */
$handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['table'] = 'commerce_library_loan';
$handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['required'] = TRUE;
/* Relationship: Commerce Loan: Product */
$handler->display->display_options['relationships']['product_id']['id'] = 'product_id';
$handler->display->display_options['relationships']['product_id']['table'] = 'commerce_library_loan';
$handler->display->display_options['relationships']['product_id']['field'] = 'product_id';
$handler->display->display_options['relationships']['product_id']['required'] = TRUE;
/* Relationship: Commerce Order: Owner */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
$handler->display->display_options['relationships']['uid']['relationship'] = 'order_id';
$handler->display->display_options['relationships']['uid']['required'] = TRUE;
/* Field: Commerce Loan: Loan ID */
$handler->display->display_options['fields']['loan_id']['id'] = 'loan_id';
$handler->display->display_options['fields']['loan_id']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['loan_id']['field'] = 'loan_id';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
/* Field: Commerce Order: Order ID */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['relationship'] = 'order_id';
$handler->display->display_options['fields']['order_id']['link_to_order'] = 'admin';
/* Field: Commerce Product: SKU */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['relationship'] = 'product_id';
$handler->display->display_options['fields']['sku']['link_to_product'] = 0;
/* Field: Commerce Loan: Product ID */
$handler->display->display_options['fields']['product_id']['id'] = 'product_id';
$handler->display->display_options['fields']['product_id']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['product_id']['field'] = 'product_id';
$handler->display->display_options['fields']['product_id']['link_to_product'] = 1;
/* Field: Commerce Loan: Loan amount */
$handler->display->display_options['fields']['amount']['id'] = 'amount';
$handler->display->display_options['fields']['amount']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['amount']['field'] = 'amount';
$handler->display->display_options['fields']['amount']['separator'] = '';
/* Field: Commerce Loan: Loan status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: Commerce Loan: Due date */
$handler->display->display_options['fields']['due']['id'] = 'due';
$handler->display->display_options['fields']['due']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['due']['field'] = 'due';
$handler->display->display_options['fields']['due']['date_format'] = 'd_m_y_24h';
$handler->display->display_options['fields']['due']['second_date_format'] = 'search_api_facetapi_YEAR';
$handler->display->display_options['fields']['due']['format_date_sql'] = 0;
/* Field: Commerce Loan: Fullfilled date */
$handler->display->display_options['fields']['fullfilled']['id'] = 'fullfilled';
$handler->display->display_options['fields']['fullfilled']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['fullfilled']['field'] = 'fullfilled';
$handler->display->display_options['fields']['fullfilled']['date_format'] = 'd_m_y_24h';
$handler->display->display_options['fields']['fullfilled']['second_date_format'] = 'search_api_facetapi_YEAR';
$handler->display->display_options['fields']['fullfilled']['format_date_sql'] = 0;
/* Field: Commerce Loan: Return link */
$handler->display->display_options['fields']['return_loan']['id'] = 'return_loan';
$handler->display->display_options['fields']['return_loan']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['return_loan']['field'] = 'return_loan';
$handler->display->display_options['fields']['return_loan']['label'] = '';
$handler->display->display_options['fields']['return_loan']['element_label_colon'] = FALSE;
/* Sort criterion: Commerce Loan: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'commerce_library_loan';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['granularity'] = 'day';
/* Sort criterion: Commerce Loan: Due date */
$handler->display->display_options['sorts']['due']['id'] = 'due';
$handler->display->display_options['sorts']['due']['table'] = 'commerce_library_loan';
$handler->display->display_options['sorts']['due']['field'] = 'due';
$handler->display->display_options['sorts']['due']['granularity'] = 'day';
/* Sort criterion: Commerce Loan: Fullfilled date */
$handler->display->display_options['sorts']['fullfilled']['id'] = 'fullfilled';
$handler->display->display_options['sorts']['fullfilled']['table'] = 'commerce_library_loan';
$handler->display->display_options['sorts']['fullfilled']['field'] = 'fullfilled';
$handler->display->display_options['sorts']['fullfilled']['granularity'] = 'day';
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['relationship'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['group'] = 1;
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
  2 => '2',
);
/* Filter criterion: Commerce Product: SKU */
$handler->display->display_options['filters']['sku']['id'] = 'sku';
$handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
$handler->display->display_options['filters']['sku']['field'] = 'sku';
$handler->display->display_options['filters']['sku']['relationship'] = 'product_id';
$handler->display->display_options['filters']['sku']['group'] = 1;
$handler->display->display_options['filters']['sku']['exposed'] = TRUE;
$handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['label'] = 'SKU';
$handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
$handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
  2 => '2',
);
/* Filter criterion: Commerce Loan: Loan status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'commerce_library_loan';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
  2 => '2',
);
/* Filter criterion: Commerce Loan: Returned date */
$handler->display->display_options['filters']['returned']['id'] = 'returned';
$handler->display->display_options['filters']['returned']['table'] = 'commerce_library_loan';
$handler->display->display_options['filters']['returned']['field'] = 'returned';
$handler->display->display_options['filters']['returned']['operator'] = 'empty';

/* Display: Admin Page */
$handler = $view->new_display('page', 'Admin Page', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Commerce Loans';
$handler->display->display_options['display_description'] = 'Loan administration list';
$handler->display->display_options['path'] = 'admin/commerce/loans/list';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'Loans';
$handler->display->display_options['menu']['description'] = 'Administer product lending';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['type'] = 'normal';
$handler->display->display_options['tab_options']['title'] = 'Loans';
$handler->display->display_options['tab_options']['description'] = 'Administer product loans';
$handler->display->display_options['tab_options']['weight'] = '0';
$handler->display->display_options['tab_options']['name'] = 'management';

/* Display: Admin Page Late Loans */
$handler = $view->new_display('page', 'Admin Page Late Loans', 'page_1');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Late loans';
$handler->display->display_options['display_description'] = 'Displays late loans';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['relationship'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['group'] = 1;
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
  2 => '2',
);
/* Filter criterion: Commerce Product: SKU */
$handler->display->display_options['filters']['sku']['id'] = 'sku';
$handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
$handler->display->display_options['filters']['sku']['field'] = 'sku';
$handler->display->display_options['filters']['sku']['relationship'] = 'product_id';
$handler->display->display_options['filters']['sku']['exposed'] = TRUE;
$handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['label'] = 'SKU';
$handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
$handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
  2 => '2',
);
/* Filter criterion: Commerce Loan: Due date */
$handler->display->display_options['filters']['due']['id'] = 'due';
$handler->display->display_options['filters']['due']['table'] = 'commerce_library_loan';
$handler->display->display_options['filters']['due']['field'] = 'due';
$handler->display->display_options['filters']['due']['operator'] = '<';
$handler->display->display_options['filters']['due']['value']['value'] = 'now';
$handler->display->display_options['filters']['due']['value']['type'] = 'offset';
/* Filter criterion: Commerce Loan: Fullfilled date */
$handler->display->display_options['filters']['fullfilled']['id'] = 'fullfilled';
$handler->display->display_options['filters']['fullfilled']['table'] = 'commerce_library_loan';
$handler->display->display_options['filters']['fullfilled']['field'] = 'fullfilled';
$handler->display->display_options['filters']['fullfilled']['operator'] = 'not empty';
/* Filter criterion: Commerce Loan: Loan status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'commerce_library_loan';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = array(
  'completed' => 'completed',
);
/* Filter criterion: Commerce Loan: Returned date */
$handler->display->display_options['filters']['returned']['id'] = 'returned';
$handler->display->display_options['filters']['returned']['table'] = 'commerce_library_loan';
$handler->display->display_options['filters']['returned']['field'] = 'returned';
$handler->display->display_options['filters']['returned']['operator'] = 'empty';
$handler->display->display_options['path'] = 'admin/commerce/loans/late';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Late loans';
$handler->display->display_options['menu']['description'] = 'View loans that are late';
$handler->display->display_options['menu']['weight'] = '10';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Returns */
$handler = $view->new_display('page', 'Returns', 'page_2');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Returns';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Commerce Loan: Loan ID */
$handler->display->display_options['fields']['loan_id']['id'] = 'loan_id';
$handler->display->display_options['fields']['loan_id']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['loan_id']['field'] = 'loan_id';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
/* Field: Commerce Order: Order ID */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['relationship'] = 'order_id';
$handler->display->display_options['fields']['order_id']['link_to_order'] = 'admin';
/* Field: Commerce Product: SKU */
$handler->display->display_options['fields']['sku']['id'] = 'sku';
$handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
$handler->display->display_options['fields']['sku']['field'] = 'sku';
$handler->display->display_options['fields']['sku']['relationship'] = 'product_id';
$handler->display->display_options['fields']['sku']['link_to_product'] = 0;
/* Field: Commerce Loan: Product ID */
$handler->display->display_options['fields']['product_id']['id'] = 'product_id';
$handler->display->display_options['fields']['product_id']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['product_id']['field'] = 'product_id';
$handler->display->display_options['fields']['product_id']['link_to_product'] = 1;
/* Field: Commerce Loan: Loan amount */
$handler->display->display_options['fields']['amount']['id'] = 'amount';
$handler->display->display_options['fields']['amount']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['amount']['field'] = 'amount';
$handler->display->display_options['fields']['amount']['separator'] = '';
/* Field: Commerce Loan: Loan status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['status']['field'] = 'status';
/* Field: Commerce Loan: Due date */
$handler->display->display_options['fields']['due']['id'] = 'due';
$handler->display->display_options['fields']['due']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['due']['field'] = 'due';
$handler->display->display_options['fields']['due']['date_format'] = 'd_m_y_24h';
$handler->display->display_options['fields']['due']['second_date_format'] = 'search_api_facetapi_YEAR';
$handler->display->display_options['fields']['due']['format_date_sql'] = 0;
/* Field: Commerce Loan: Fullfilled date */
$handler->display->display_options['fields']['fullfilled']['id'] = 'fullfilled';
$handler->display->display_options['fields']['fullfilled']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['fullfilled']['field'] = 'fullfilled';
$handler->display->display_options['fields']['fullfilled']['date_format'] = 'd_m_y_24h';
$handler->display->display_options['fields']['fullfilled']['second_date_format'] = 'search_api_facetapi_YEAR';
$handler->display->display_options['fields']['fullfilled']['format_date_sql'] = 0;
/* Field: Commerce Loan: Returned date */
$handler->display->display_options['fields']['returned']['id'] = 'returned';
$handler->display->display_options['fields']['returned']['table'] = 'commerce_library_loan';
$handler->display->display_options['fields']['returned']['field'] = 'returned';
$handler->display->display_options['fields']['returned']['label'] = 'Returned';
$handler->display->display_options['fields']['returned']['date_format'] = 'short';
$handler->display->display_options['fields']['returned']['second_date_format'] = 'search_api_facetapi_YEAR';
$handler->display->display_options['fields']['returned']['format_date_sql'] = 0;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Commerce Loan: Returned date */
$handler->display->display_options['sorts']['returned']['id'] = 'returned';
$handler->display->display_options['sorts']['returned']['table'] = 'commerce_library_loan';
$handler->display->display_options['sorts']['returned']['field'] = 'returned';
$handler->display->display_options['sorts']['returned']['granularity'] = 'minute';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['relationship'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['group'] = 1;
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
  2 => '2',
);
/* Filter criterion: Commerce Product: SKU */
$handler->display->display_options['filters']['sku']['id'] = 'sku';
$handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
$handler->display->display_options['filters']['sku']['field'] = 'sku';
$handler->display->display_options['filters']['sku']['relationship'] = 'product_id';
$handler->display->display_options['filters']['sku']['group'] = 1;
$handler->display->display_options['filters']['sku']['exposed'] = TRUE;
$handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['label'] = 'SKU';
$handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
$handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
$handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
  2 => '2',
);
/* Filter criterion: Commerce Loan: Returned date */
$handler->display->display_options['filters']['returned']['id'] = 'returned';
$handler->display->display_options['filters']['returned']['table'] = 'commerce_library_loan';
$handler->display->display_options['filters']['returned']['field'] = 'returned';
$handler->display->display_options['filters']['returned']['operator'] = 'not empty';
$handler->display->display_options['filters']['returned']['group'] = 1;
$handler->display->display_options['path'] = 'admin/commerce/loans/returns';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Returns';
$handler->display->display_options['menu']['description'] = 'View loans that have been returned';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['commerce_loan_admin_view'] = array(
  t('Master'),
  t('Returns'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Displaying @start - @end of @total'),
  t('Order ID'),
  t('Product ID'),
  t('Order owner'),
  t('Loan ID'),
  t('.'),
  t(','),
  t('Name'),
  t('SKU'),
  t('Loan amount'),
  t('Loan status'),
  t('Due date'),
  t('Fullfilled date'),
  t('User'),
  t('Status'),
  t('Admin Page'),
  t('Commerce Loans'),
  t('Loan administration list'),
  t('Admin Page Late Loans'),
  t('Late loans'),
  t('Displays late loans'),
  t('Returned'),
);

