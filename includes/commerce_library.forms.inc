<?php

/**
 * Loan return confirmation form
 */
function commerce_library_return_form($form, &$form_state, $loan) {
  $form_state['loan'] = $loan;
  $product=commerce_product_load($loan->product_id);

  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'commerce_order') . '/includes/commerce_library.forms.inc';

  $form['#submit'][] = 'commerce_library_return_form_submit';

  $form['product']['#markup'] = '<h3>' . t('Return product @sku', array('@sku'=>$product->sku)) . '</h3>';
  $form['details']=array(
    '#theme' => 'table',
    '#header' => array(t('SKU'), t('Title'), t('Amount'), t('Due')),
    '#rows' => array(0=>array($product->sku, $product->title, $loan->amount, format_date($loan->due) )),
    '#caption' => t('Product'),
  );

  if ($loan->status=='pending')
    $form['pending']['#markup'] = '<p>'.t('Note: The product has not been delivered yet!').'</p>';

  $form = confirm_form($form,
    t('Are you sure you want to return loan @number?', array('@number' => $loan->loan_id)),
    '/admin/commerce/loans',
    null,
    t('Return loan'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

function commerce_library_return_form_submit($form, &$form_state) {
  $loan = $form_state['loan'];

  if (commerce_library_loan_return($loan)) {
    drupal_set_message(t('Loan @number has been returned.', array('@number' => $loan->loan_id)));
    watchdog('commerce_library', 'Returned loan @number.', array('@number' => $loan->loan_id), WATCHDOG_NOTICE);
    $form_state['redirect']='/admin/commerce/loans';
  } else {
    drupal_set_message(t('Loan @number could not be returned.', array('@number' => $loan->loan_id)), 'error');
  }
}


/*********************************************************************************************************************/

/**
 * Loan renew confirmation form
 */
function commerce_library_renew_form($form, &$form_state, $loan) {
  $form_state['loan'] = $loan;
  $product=commerce_product_load($loan->product_id);

  // Ensure this include file is loaded when the form is rebuilt from the cache.
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'commerce_order') . '/includes/commerce_library.forms.inc';

  $form['#submit'][] = 'commerce_library_renew_form_submit';

  $form['product']['#markup'] = '<h3>' . t('Renew loan of product @sku', array('@sku'=>$product->sku)) . '</h3>';
  $form['details']=array(
    '#theme' => 'table',
    '#header' => array(t('SKU'), t('Title'), t('Amount'), t('Due')),
    '#rows' => array(0=>array($product->sku, $product->title, $loan->amount, format_date($loan->due) )),
    '#caption' => t('Product'),
  );

  if ($loan->status=='pending')
    $form['pending']['#markup'] = '<p>'.t('Note: The product has not been delivered yet!').'</p>';

  // XXX: Add option to enter custom days for renew

  $form = confirm_form($form,
    t('Are you sure you want to renew loan @number?', array('@number' => $loan->loan_id)),
    '/admin/commerce/loans',
    null,
    t('Renew loan'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

function commerce_library_renew_form_submit($form, &$form_state) {
  $loan = $form_state['loan'];

  if (commerce_library_loan_renew($loan)) {
    drupal_set_message(t('Loan @number has been renew.', array('@number' => $loan->loan_id)));
    watchdog('commerce_library', 'Renewed loan @number.', array('@number' => $loan->loan_id), WATCHDOG_NOTICE);
    $form_state['redirect']='/admin/commerce/loans';
  } else {
    drupal_set_message(t('Loan @number could not be renwed.', array('@number' => $loan->loan_id)), 'error');
  }
}
