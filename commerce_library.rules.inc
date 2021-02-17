<?php

/**
 * @file
 * Rules integration for Commerce Library
 */

/**
 * Implements hook_rules_condition_info().
 */
function commerce_library_rules_condition_info() {
  $conditions = array();

  $conditions['commerce_library_loan_enabled_on_product'] = array(
    'label' => t('Product loan is enabled for this type'),
    'parameter' => array(
      'commerce_product' => array(
        'type' => 'commerce_product',
        'label' => t('product'),
      ),
    ),
    'group' => t('Commerce Library'),
    'callbacks' => array(
      'execute' => 'commerce_library_product_enabled',
    ),
  );

  return $conditions;
}

/**
 * Implements hook_rules_action_info().
 */
function __commerce_library_rules_action_info() {
  $actions = array();

  return $actions;
}
