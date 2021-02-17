<?php

/**
 * @file
 * The controller for the order entity containing the CRUD operations.
 */

/**
 * The controller class for orders contains methods for the order CRUD
 * operations. The load method is inherited from the default controller.
 */
class CommerceLibraryLoanEntityController extends DrupalCommerceEntityController {

  /**
   * Create a default loan.
   *
   */
  public function create(array $values = array()) {
    $values += array(
      'loan_id' => NULL,
      'order_id' => NULL,
      'product_id' => NULL,
      'type'=>'commerce_library_loan',
      'amount' => 0,
      'reloaned' => 0,
      'status' => 'pending',
      'created' => '',
      'fullfilled' => '',
      'due' => '',
    );

    return parent::create($values);
  }

  /**
   * Saves a loan.
   *
   * When saving an order without an order ID, this function will create a new
   * order at that time. For new orders, it will also determine and save the
   * order number and then save the initial revision of the order. Subsequent
   * orders that should be saved as new revisions should set $order->revision to
   * TRUE and include a log string in $order->log.
   *
   * @param $order
   *   The full order object to save.
   * @param $transaction
   *   An optional transaction object.
   *
   * @return
   *   SAVED_NEW or SAVED_UPDATED depending on the operation performed.
   */
  public function save($loan, DatabaseTransaction $transaction = NULL) {
    if (!isset($transaction)) {
      $transaction = db_transaction();
      $started_transaction = TRUE;
    }

    try {
      // Determine if we will be inserting a new order.
      $loan->is_new = empty($loan->loan_id);

      // Set the timestamp fields.
      if ($loan->is_new) {
        if (empty($loan->created)) {
          $loan->created = REQUEST_TIME;
	  $loan->fullfilled=0;
	  $loan->due=0;
        }
      } else {
        if ($loan->created === '') {
          unset($loan->created);
        }
      }

      return parent::save($loan, $transaction);
    }
    catch (Exception $e) {
      if (!empty($started_transaction)) {
        $transaction->rollback();
        watchdog_exception($this->entityType, $e);
      }
      throw $e;
    }
  }

  /**
   * Unserializes the data property of loaded orders.
   */
  public function attachLoad(&$queried_loans, $revision_id = FALSE) {
    //foreach ($queried_orders as $order_id => &$order) {
    //  $order->data = unserialize($order->data);
    //}

    // Call the default attachLoad() method. This will add fields and call
    parent::attachLoad($queried_loans, $revision_id);
  }

  /**
   * Deletes multiple orders by ID.
   *
   * @param $order_ids
   *   An array of order IDs to delete.
   * @param $transaction
   *   An optional transaction object.
   *
   * @return boolean
   *   TRUE on success, FALSE otherwise.
   */
  public function delete($order_ids, DatabaseTransaction $transaction = NULL) {
    // Loans can not be deleted, ever
    return FALSE;
  }
}
