<?php

function commerce_library_contents_pane_review($form, $form_state, $checkout_pane, $order) {
  $loans=commerce_library_extract_lendable_products($order);

  if (empty($loans))
    return;

  $rows=array();
  foreach ($loans as $loan) {
    $days=$loan->product_class->commerce_library['und'][0]['value'];
    $rows[]=array($loan->product_class->sku, $loan->product_class->title, $loan->quantity, $days);
  }

  $table = array(
    '#theme' => 'table',
    '#header' => array(t('SKU'), t('Product'), t('Quantity'), t('Loan period')),
    '#rows' => $rows,
  );

  return drupal_render($table);
}

