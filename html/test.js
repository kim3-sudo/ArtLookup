$(document).ready(function () {
  document.cookie = "memberId=4;username=sammy";
  // document.cookie = "Michaela=gone";
  // document.cookie = "John=done";
  // document.cookie = "Michaela=crazy";
  var decodedCookie = decodeURIComponent(document.cookie);
  var parsed = decodedCookie.split(';');
  console.log("Number of Cookies: ", parsed.length);
  for (var i=0; i<parsed.length; i++) {
    console.log(parsed[i]);
  }
  console.log("Done");
});