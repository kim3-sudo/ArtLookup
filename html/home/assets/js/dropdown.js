$(document).ready(function(){
  /*begin tester function*/
  // Solution is from https://stackoverflow.com/questions/33413106/show-selected-option-in-bootstrap-dropdown-list-menu
  $('.dropdown-menu a').click(function(){
    $('#selected').text($(this).text());
    //something is taking precedence over this JS file, but I can't figure out why...
  });
  /*end tester function*/
  /*begin tester function
  $(".dropdown-menu li a").click(function(){
    $(this).parents(".dropdown").find('.btn').html($(this).text() + ' <span class="caret"></span>');
    $(this).parents(".dropdown").find('.btn').val($(this).data('value'));
  });
  end tester function*/
});
