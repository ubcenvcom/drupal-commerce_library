<?php

/**
 * @file
 * Contains the resource callbacks for loans.
 */


/**
 * Returns a collection of loans.
 *
 * @see commerce_services_index_entities()
 */
function commerce_library_services_loan_index($fields, $expand_entities, $flatten_fields, $filter, $filter_op, $sort_by, $sort_order, $limit, $offset) {
  return commerce_services_index_entities('commerce_library_loan', $fields, $expand_entities, $flatten_fields, $filter, $filter_op, $sort_by, $sort_order, $limit, $offset);
}

/**
 * Determines an API user's access to index loans.
 */
function commerce_library_services_loan_index_access() {
  // Because the entity access control system will filter any result sets,
  // there's no reason to limit a particular user's access.
  return TRUE;
}

/**
 * Returns a single loan.
 *
 * @see commerce_services_retrieve_entity()
 */
function commerce_library_services_loan_retrieve($loan_id, $expand_entities, $flatten_fields) {
  return commerce_services_retrieve_entity('commerce_library_loan', $loan_id, $expand_entities, $flatten_fields);
}

/**
 * Determines an API user's access to retrieve a given loan.
 *
 * @param $loan_id
 *   The ID of the loan to be retrieved.
 *
 * @return
 *   Boolean indicating the user's access to retrieve the loan.
 */
function commerce_library_services_loan_retrieve_access($loan_id) {
  // Attempt to load the loan.
  if ($loan = commerce_library_loan_load($loan_id)) {
    if (commerce_library_loan_access('view', $loan)) {
      return TRUE;
    } else {
      return services_error(t('Access to this operation not granted'), 401);
    }
  }

  return services_error(t('Loan not found'), 404);
}

/**
 * Updates an loan.
 *
 * @see commerce_services_update_entity()
 */
function commerce_library_services_loan_update($loan_id, $data, $flatten_fields) {
  return commerce_services_update_entity('commerce_library_loan', $loan_id, $data, $flatten_fields);
}

/**
 * Determines an API user's access to update a given loan.
 *
 * @param $loan_id
 *   The ID of the loan to be updated.
 *
 * @return
 *   Boolean indicating the user's access to update the loan.
 */
function commerce_library_services_loan_update_access($loan_id) {
  // Attempt to load the loan.
  if ($loan = commerce_library_loan_load($loan_id)) {
    if (commerce_library_loan_access('update', $loan)) {
      return TRUE;
    } else {
      return services_error(t('Access to this operation not granted'), 401);
    }
  }

  return services_error(t('Loan not found'), 404);
}

/**
 * Returns a collection of line items on an loan.
 *
 * @see commerce_services_index_entities()
 */
function commerce_library_services_loan_line_item_index($loan_id, $fields, $expand_entities, $flatten_fields, $filter, $filter_op, $sort_by, $sort_order, $limit, $offset) {
  // XXX!!!

  // Add the order ID to the filter list.
  $filter['order_id'] = $order_id;
  $filter_op['order_id'] = '=';

  return commerce_services_index_entities('commerce_line_item', $fields, $expand_entities, $flatten_fields, $filter, $filter_op, $sort_by, $sort_order, $limit, $offset);
}

/**
 * Determines an API user's access to index line items on an order.
 */
function commerce_library_services_order_line_item_index_access($order_id) {
  // Attempt to load the order.
  if ($order = commerce_order_load($order_id)) {
    if (commerce_order_access('view', $order)) {
      return TRUE;
    } else {
      return services_error(t('Access to this operation not granted'), 401);
    }
  }

  return services_error(t('Loan not found'), 404);
}
