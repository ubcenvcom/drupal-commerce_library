<?php

/**
 * Implements hook_views_data()
 */
function commerce_library_views_data() {
  $data = array();

  /* XXX: Do we need this ?
  $data['views']['view_loan_form'] = array(
    'title' => t('View loan form'),
    'help' => t('Display a form that redirects to the view page for a product loan.'),
    'area' => array(
      'handler' => 'commerce_library_handler_area_view_loan_form'
    ),
  );
  */

  $data['commerce_library_loan']['table']['group']  = t('Commerce Loan');

  $data['commerce_library_loan']['table']['base'] = array(
    'field' => 'loan_id',
    'title' => t('Commerce Loan'),
    'help' => t('Product loan from the store.'),
    'access query tag' => 'commerce_order_access',
  );
  $data['commerce_library_loan']['table']['entity type'] = 'commerce_library_loan';
  
  // Expose the ID.
  $data['commerce_library_loan']['loan_id'] = array(
    'title' => t('Loan ID', array(), array('context' => 'a drupal commerce loan')),
    'help' => t('The unique internal identifier of the loan.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
      'validate type' => 'loan_id',
    ),
  );

  // Expose return link to operate on the loan.
  $data['commerce_library_loan']['return_loan'] = array(
    'field' => array(
      'title' => t('Return link'),
      'help' => t('Provide a link for returning the loan.'),
      'handler' => 'commerce_library_handler_field_loan_link',
    ),
  );

  // Expose the order id relation.
  $data['commerce_library_loan']['order_id'] = array(
    'title' => t('Order ID'),
    'help' => t("The order ID."),
    'field' => array(
      'handler' => 'commerce_order_handler_field_order',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'commerce_order_handler_argument_order_order_id',
      'name field' => 'order_number',
      'numeric' => TRUE,
      'validate type' => 'order_id',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Order'),
      'help' => t("Relate this loan to its order"),
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_order',
      'base field' => 'order_id',
      'field' => 'order_id',
      'label' => t('Order ID'),
    ),
  );

// Expose the product id relation.
  $data['commerce_library_loan']['product_id'] = array(
    'title' => t('Product ID'),
    'help' => t("The loaned product ID."),
    'field' => array(
      'handler' => 'commerce_product_handler_field_product',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'commerce_product_handler_argument_product_id',
      'numeric' => TRUE,
      'validate type' => 'product_id',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'title' => t('Product'),
      'help' => t("Relate this loan to its product"),
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_product',
      'base field' => 'product_id',
      'field' => 'product_id',
      'label' => t('Product ID'),
    ),
  );

  // Expose the amount of products.
  $data['commerce_library_loan']['amount'] = array(
    'title' => t('Loan amount'),
    'help' => t('The amount of products.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Expose the order status.
  $data['commerce_library_loan']['status'] = array(
    'title' => t('Loan status'),
    'help' => t('The lending status of the order.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'commerce_library_handler_filter_loan_state',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Expose the created, changed, and placed timestamps.
  $data['commerce_library_loan']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the loan was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_library_loan']['created_fulldate'] = array(
    'title' => t('Created date'),
    'help' => t('In the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['commerce_library_loan']['created_year_month'] = array(
    'title' => t('Created year + month'),
    'help' => t('In the form of YYYYMM.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['commerce_library_loan']['created_timestamp_year'] = array(
    'title' => t('Created year'),
    'help' => t('In the form of YYYY.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['commerce_library_loan']['created_month'] = array(
    'title' => t('Created month'),
    'help' => t('In the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['commerce_library_loan']['created_day'] = array(
    'title' => t('Created day'),
    'help' => t('In the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['commerce_library_loan']['created_week'] = array(
    'title' => t('Created week'),
    'help' => t('In the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );

  /*
  $data['commerce_library']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the order was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_library']['changed_fulldate'] = array(
    'title' => t('Updated date'),
    'help' => t('In the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['commerce_library']['changed_year_month'] = array(
    'title' => t('Updated year + month'),
    'help' => t('In the form of YYYYMM.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['commerce_library']['changed_timestamp_year'] = array(
    'title' => t('Updated year'),
    'help' => t('In the form of YYYY.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['commerce_library']['changed_month'] = array(
    'title' => t('Updated month'),
    'help' => t('In the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['commerce_library']['changed_day'] = array(
    'title' => t('Updated day'),
    'help' => t('In the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['commerce_library']['changed_week'] = array(
    'title' => t('Updated week'),
    'help' => t('In the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );
  */

  $data['commerce_library_loan']['placed'] = array(
    'title' => t('Placed date'),
    'help' => t('The date the order was placed.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_library_loan']['placed_fulldate'] = array(
    'title' => t('Placed date'),
    'help' => t('In the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'placed',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['commerce_library_loan']['placed_year_month'] = array(
    'title' => t('Placed year + month'),
    'help' => t('In the form of YYYYMM.'),
    'argument' => array(
      'field' => 'placed',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['commerce_library_loan']['placed_timestamp_year'] = array(
    'title' => t('Placed year'),
    'help' => t('In the form of YYYY.'),
    'argument' => array(
      'field' => 'placed',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['commerce_library_loan']['placed_month'] = array(
    'title' => t('Placed month'),
    'help' => t('In the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'placed',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['commerce_library_loan']['placed_day'] = array(
    'title' => t('Placed day'),
    'help' => t('In the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'placed',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['commerce_library_loan']['placed_week'] = array(
    'title' => t('Placed week'),
    'help' => t('In the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'placed',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );

  // Fullfilled
  $data['commerce_library_loan']['fullfilled'] = array(
    'title' => t('Fullfilled date'),
    'help' => t('The date the loan was fullfilled.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Due date
  $data['commerce_library_loan']['due'] = array(
    'title' => t('Due date'),
    'help' => t('The date the loan is due.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Return date
  $data['commerce_library_loan']['returned'] = array(
    'title' => t('Returned date'),
    'help' => t('The date the loan was returned.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // XXX: Expose links to operate on the loan.
  /*
  $data['commerce_library']['view_loan'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the loan.'),
      'handler' => 'commerce_library_handler_field_loan_link',
    ),
  );
  */

  return $data;
}

/**
 * Implements hook_views_plugins
 */
function commerce_library_views_plugins() {
  return array(
    'argument validator' => array(
      'current_user_or_role' => array(
        'title' => t('Current user or role'),
        'handler' => 'commerce_library_plugin_argument_validate_user',
      ),
    ),
  );
}
