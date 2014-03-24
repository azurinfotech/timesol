<table class="form-table">
  <tbody>
    <tr><td ><?php print drupal_render($form['firstname']); ?></td><td ><?php print drupal_render($form['lastname']); ?></td></tr>
  	<tr><td><?php print drupal_render($form['qualification']); ?></td><td ><?php print drupal_render($form['type']); ?></td></tr>
    <tr><td><?php print drupal_render($form['sdate']); ?></td></tr>
    </tbody>
</table>
<?php print drupal_render_children($form); ?>