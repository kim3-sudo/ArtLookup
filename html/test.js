$(document).ready(function () {
  console.log("tester");
  console.log("String " + "concatenation.");
  var object = "string to be parsed;";
  var parsedOb = object.split(';');
  console.log(parsedOb.length);
  document.cookie = "Michaela=here";
  document.cookie = "Michaela=gone";
  document.cookie = "John=done";
  document.cookie = "Michaela=crazy";
  var decodedCookie = decodeURIComponent(document.cookie);
  var parsed = decodedCookie.split(';');
  for (var i=0; i<parsed.length; i++) {
    console.log(parsed[i]);
  }
});