var searchCategory;  //Category to be searched by: Title, Author ...
var ajaxUser = "brydon1"; //Your username for ajax calls

$(document).ready(function () {
  console.log("ready!");
  checkCookie();
  // When category chosen from dropdown, setCategory
  $(".dropdown-item").click(setCategory);
  // getMatches when search button is clicked
  $(".action-button").click(getSearchMatches);
  // when submit-user-cred button clicked, addMember
  $("#submit-user-credentials").click(addMember);
  $("#loginButton").click(loginMember);
  $("#logout").click(logoutMember);
});

function setCategory(){
  //Set the category to the text of the dropdown-item
  searchCategory = $(this).text();
  // Maybe will not work???
  $("#searchtype").text(searchCategory);
}

//Switches to search page and displays the photos related to the user's search
function getSearchMatches(){
    //Hides the search page and shows the homepage
    var searchTerm = $('#search-field2').val();
    $('#home').hide();
    console.log("hide the homepage");
    $('#search').show();
    console.log("Show seach page");

    console.log("Search Term: " + searchTerm);
    console.log("Search Category: " + searchCategory)

    //Sends search term and category to C++ then calls processResults
    $.ajax({
      url: '/cgi-bin/'+ajaxUser+'_artAppSearch.cgi?searchVal='+searchTerm+'&searchCategory='+searchCategory,
      dataType: 'text',
      success: processSearchResults,
      error: function(){alert("Error: Could not search");}
    });
}

//Empties photo gallery (again?) builds new gallery using buildGallery function
function processSearchResults(results) {
    console.log("Results:"+results);
    $('#artworkResults').empty();
    $('#artworkResults').append(showPhotos(results));
}

//Parses art data from c++. Appends all photos to photo gallery
function showPhotos(list){
  var artData = list.split("*");

  //If there is nothing from c++ return "Internal Error"
  if (artData.length < 1) {
    return "<h3>Internal Error</h3>";
  } else {

      var result = '<div class="row" style="padding-top: 70px;"><div class="col d-flex float-none"><div class="border rounded border-dark" style="width: 100%;">';

      var listLength = artData.length;
      console.log("Length of artData List: ");
      console.log(listLength);
      console.log("Appending Results: \n\n");

      for (var i = 6; i < listLength; i+=13){
        console.log(i);
        console.log("ArtData[i]: ");
        console.log(artData[i]);

        //Creates image
        result += '<img class="img-fluid lazyload" src=' + artData[i] + ' height="100%" align="left" style = "padding-top: 20px; padding-right: 10px">';
        //Creates description
        result += '<p style="padding-top: 20px;">Title: ' + artData[i-3] + '<br><br>Author: ' + artData[i-5] + ' ' + artData[i-4] + '<br>Location: ' + artData[i-1] + '<br>Date: ' + artData[i+5] + '<br>Technique: ' + artData[i-2] + '<br>School: ' + artData[i+3] + '<br>Type: ' + artData[i+2] + '<br>Form: ' + artData[i+1] + '</p>';
        //Creates like button
        result += '<button class="btn btn-warning text-center likeClass" type="button" style="margin-top: 0px;margin-bottom: 10px;">like!</button>';
        //Creates comment field and submit button
        result += '<form><div class="form-group"><input class="form-control commentClass" style="padding-top: 10px" type="text" placeholder="comment here!"><button class="btn btn-outline-dark" type="button" style="margin-bottom: 70px;margin-top: 10px;">submit</button>';
        //Adds closing tags
        result += '</div></form></div></div></div>';
      }
    return result;
  }
}

// Adds member to user table in SQL database if user does not already exist;
// Otherwise, shows error message
function addMember(){
  console.log("Clicked-signup");

  username = $('#signup-username').val();
  console.log(username);
  email = $('#signup-email').val();
  console.log(email);
  password1 = $('#signup-password').val();
  console.log(password1);
  password2 = $('#signup-password-repeated').val();
  console.log(password2);

  if (password1 === password2) { // strict equality with ===
    console.log("Sending info to server");
    $.ajax({
      url: '/cgi-bin/'+ajaxUser+'_artAppAddMember.cgi?userName='+username+'&email='+email+'&password='+password1,
      dataType: 'text',
      success: isUsernameAvailable, // cgi should return character T if username not taken; F otherwise
      error: function(){alert("Error: Something went wrong");}
    });

  } else {
    console.log("Passwords do not match");
    //alert("Passwords do not match."); // I think this is how you do this??
  }
}

function isUsernameAvailable(results){
  console.log(results);
  console.log("Results: " + results);
  if (results == "Success"){
    //var node = document.createElement("DIV");
    //var textNode = document.createTextNode("Water");
    console.log("Signup successful");
    // Close modal
    document.getElementById("signupModal").setAttribute("style", "display: none");
    document.getElementById("loginModal").setAttribute("style", "display: block");
    document.getElementById("loginModal").setAttribute("class", "modal fade show");
  } else {
    console.log("Signup failure.");
  }
}

// Login member
function loginMember(){
  console.log("Clicked Log In");
  email = $('#login-email').val();
  console.log(email);
  password = $('#login-password').val();
  console.log(password);

  if (email == "" || password == ""){
    alert("Invalid entry.");
  } else {
    console.log("Sending info to server");
    $.ajax({
      url: '/cgi-bin/'+ajaxUser+'_artAppSigninMember.cgi?email='+email+'&password='+password,
      dataType: 'text',
      success: processLoginResults,
      error: function(){alert("Error: Something went wrong");}
    });
  }
}

// Process login results
function processLoginResults(results){
  console.log("Result: ");
  console.log(results);
  if (results == ""){
    console.log("Login unsuccessful :(");
    document.cookie = "username=";
    $("#invalid_login").show();
  } else {
    console.log("Login successful!");
    $("#invalid_login").hide();
    $("#start-signup").hide();
    $("#start-login").hide();
    $("#logout").show();
    document.cookie = "username=" + results + ";";

    // Close login modal
    document.getElementById("loginModal").setAttribute("style", "display: none");
    document.getElementById("loginModal").setAttribute("class", "modal fade hide");
    $(".modal-backdrop").hide();
  }
  if (document.cookie == "username="){
    console.log("No one logged in.");
  } else {
  console.log(getCookie("username"));
  console.log("is logged in!");
  }
}

// Returns value assigned to cname in cookie
function getCookie(cname) {
  var name = cname + "=";
  var decodedCookie = decodeURIComponent(document.cookie);
  var ca = decodedCookie.split(';');
  for (var i=0; i<ca.length; i++) {
    var c = ca[i];
    while (c.charAt(0) == ' ') {
      c = c.substring(1);
    }
    if (c.indexOf(name) == 0) {
      return c.substring(name.length, c.length);
    }
  }
  return "";
}

// 
function checkCookie() {
  console.log("Checking cookie!");
  var username = getCookie("username");
  if (username != "") {
    $("#invalid_login").hide();
    $("#start-signup").hide();
    $("#start-login").hide();
    $("#logout").show();
    // Someone is logged in
    console.log(username + " logged in.");
    console.log("Someone logged in");
  } else {
    // Show normal homepage
    $("#logout").hide();
    console.log("Default page");
  }
}

// Logout member
function logoutMember() {
  $("#invalid_login").hide(); // Maybe unnecessary
  $("#start-signup").show();
  $("#start-login").show();
  $("#logout").hide();
  document.cookie = "username=";
  console.log(getCookie("username"));
  console.log("Logged out!");
}

//Login Function
//id's login-email login-password

//Signup Function
//id's signup-email signup-password signup-password-repeated
