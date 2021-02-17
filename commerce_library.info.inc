<?php

/**
 * Implements hook_entity_property_info().
 */
function ___commerce_library_entity_property_info() {
  $info = array();

  $properties = &$info['commerce_library_loan']['properties'];

  $properties['loan_id'] = array(
    'type' => 'integer',
    'label' => t('Loan ID', array(), array('context' => 'a drupal commerce loan')),
    'description' => t('The internal numeric ID of the loan.'),
    'schema field' => 'loan_id',
  );

  watchdog('commerce_library', 'commerce_library_entity_property_info 123872198379817398721987398');

  return $info;
}
