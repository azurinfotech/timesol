<table class="form-table">
  <tbody>
  	<tr><td><?php print drupal_render($form['location']); ?></td></tr>
    <tr><td ><?php print drupal_render($form['location']['emp_address']); ?></td></tr>
    <tr><td ><?php print drupal_render($form['location']['country']); ?></td></tr>
    <tr><td ><?php print drupal_render($form['location']['state']); ?></td></tr>
    <tr><td ><?php print drupal_render($form['location']['city']); ?></td></tr>
    
    <tr><td><?php print drupal_render($form['address']); ?></td></tr>
  	<tr><td><?php print drupal_render($form['address']['phone']); ?></td></tr>
  	<tr><td><?php print drupal_render($form['address']['rephone']); ?></td></tr>
    <tr><td><?php print drupal_render($form['address']['pincode']); ?></td></tr>
    </tbody>
</table>
<?php print drupal_render_children($form); ?>