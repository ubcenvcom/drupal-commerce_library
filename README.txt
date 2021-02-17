Commerce Library for Drupal 7
=============================
Enable a simple product lending system for commerce products.

Note: This is still in beta and has not received much production testing yet.

Features
========
- A specific product type can be made lendable for product specific amount of days
- Products can be ordered as usual, loans are tracked when order is completed
- Reminder e-mail to return products
- User view of lent products
- Admin view of lent, due and late products
- Admin can renew loans 
- Return of products
- Supports stock adjustment when lending/returing using commerce_stock module

WiP
===
- service API support

Todo
====
- Request renew by user
- Product reservation
- Setting arbitrary return date by admin

Installation
============
Install as any other Drupal module.
Configure product lending and reminder mails from /admin/commerce/config/library

