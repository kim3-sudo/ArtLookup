$(document).ready(function () {
  console.log("tester");
  console.log("String " + "concatenation.");
  var object = "string to be parsed;";
  var parsedOb = object.split(';');
  console.log(parsedOb.length);
});