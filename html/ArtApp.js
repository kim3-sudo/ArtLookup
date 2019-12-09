var searchCategory;  //Category to be searched by: Title, Author ...
var ajaxUser = "brydon1"; //Your username for ajax calls

$(document).ready(function () {
  console.log("ready!");
  checkCookie();
  //document.cookie = "username=John Doe";
  //checkCookie();
  $(".dropdown-item").click(setCategory);
  // getMatches when search button is clicked
  $(".action-button").click(getMatches);

  $("#submit-user-credentials").click(addMember);
  // $("#start-signup").click(function() {
  //   //console.log("Tell me I am not crazy");
  //   $("#submit-user-credentials").click(addMember);
  // });
  $("#loginButton").click(loginMember);
  $("#logout").click(logoutMember);
});

function logoutMember() {
  //$("#invalid_login").show();
  $("#start-signup").show();
  $("#start-login").show();
  $("#logout").hide();
  document.cookie = "username=";
  //setCookie("username","Sam"); // initialize cookie
  console.log(getCookie("username"));
  console.log("Logged out!");
}

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

function processLoginResults(results){
  console.log("Result: "); // Try "Results: ", results
  console.log(results);
  //if (results == 'Invalid'){
  if (results == ""){
    console.log("Login unsuccessful :(");
    document.cookie = "username=";
    $("#invalid_login").show(); // EVENTUALLY must be hidden again!!!!!!

    //alert("Signup successful."); // Maybe change to close modal
  } else {
    console.log("Login successful!");
    $("#invalid_login").hide();
    $("#start-signup").hide();
    $("#start-login").hide();
    $("#logout").show();


    document.cookie = "username=" + results + ";";
    // CLOSE MODAL 
    document.getElementById("loginModal").setAttribute("style", "display: none");
    document.getElementById("loginModal").setAttribute("class", "modal fade hide"); 
    $(".modal-backdrop").hide();
    //document.getElementById("loginModal").setAttribute("style", "display: block");
    
    
    // still need to close login modal
    // create log out button 

    // Add log out button
    // DO SOMETHING TO MAKE LOGIN KNOWN
    //alert("Username is not available.");
  }
  if (document.cookie == "username="){
    console.log("No one logged in.");
  } else {
  console.log(getCookie("username"));
  console.log("is logged in!");
  }
}

// function setCookie(cname, cvalue) {
//   document.cookie = cname + "=" + cvalue + ";path=/";
//   console.log(document.cookie);
//   console.log(getCookie(cname));
// }

// Maybe will not work
// function addCookie(cname, cvalue) {
//   document.cookie = document.cookie + ";" + cname + "=" + cvalue + ";path=/";
// }

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


    // username = prompt("Please enter your name:", "");
    // if (username != "" && username != null) {
    //   setCookie("username", username, 365);
    // }
  }
}

function setCategory(){
  //Set the category to the text of the dropdown-item
  searchCategory = $(this).text();
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
    alert("Passwords do not match."); // I think this is how you do this??
  }
}

function isUsernameAvailable(results){
  console.log(results);
  console.log("Results: " + results);
  if (results == "Success"){
    //var node = document.createElement("DIV");
    //var textNode = document.createTextNode("Water"); 
    console.log("Signup successful");
    // CLOSE MODAL 
    document.getElementById("signupModal").setAttribute("style", "display: none"); 
    document.getElementById("loginModal").setAttribute("style", "display: block");
    document.getElementById("loginModal").setAttribute("class", "modal fade show");

    //document.getElementsByTagName("body").write('<div class = "modal-backdrop fade show"></div>');
    //document.getElementsByTagName("body").setAttribute("class", "modal-open");

    // Take user to login modal
    // should it login for them?
  } else {
    console.log("Signup failure.");
    //alert("Username is not available.");
  }
}

//Switches to search page and displays the photos related to the user's search
function getMatches(){
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
    	success: processResults,
    	error: function(){alert("Error: Could not search");}
    });
}

//Empties photo gallery (again?) builds new gallery using buildGallery function
function processResults(results) {
    console.log("Results:"+results);
    $('#artworkResults').empty();
    $('#artworkResults').append( showPhotos( results ));
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
        result += '<img class="img-fluid lazyload" src=' + artData[i] + ' height="100%">';
        //Creates description
        result += '<p style="padding-top: 8px;">Title: ' + artData[i-3] + '<br><br>Author: ' + artData[i-5] + ' ' + artData[i-4] + '<br>Location: ' + artData[i-1] + '<br>Date: ' + artData[i+5] + '<br>Technique: ' + artData[i-2] + '<br>School: ' + artData[i+3] + '<br>Type: ' + artData[i+2] + '<br>Form: ' + artData[i+1] + '</p>';
        //Creates like button
        result += '<button class="btn btn-warning text-center" type="button" style="margin-top: 0px;margin-bottom: 10px;">like!</button>';
        //Creates comment field and submit button
        result += '<form><div class="form-group"><input class="form-control" type="text" placeholder="comment here!"><button class="btn btn-light" type="button" style="margin-bottom: 70px;margin-top: 10px;">submit</button>';
        //Adds closing tags
        result += '</div></form></div></div></div>';
      }
    return result;
  }
}

//Login Function
//id's login-email login-password

//Signup Function
//id's signup-email signup-password signup-password-repeated
