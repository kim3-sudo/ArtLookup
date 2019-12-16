var searchCategory;  //Category to be searched by: Title, Author ...
var ajaxUser = "brydon1"; //Your username for ajax calls

$(document).ready(function () {
  console.log("ready!");
  setNavButtonView(); // CHANGE function name
  // $("#home").show();

  // When category chosen from dropdown, setCategory
  $(".dropdown-item").click(setCategory);
  // getMatches when search button is clicked
  $(".action-button").click(function () {
    console.log("About to search");
    getSearchMatches(this)
  });
  // when submit-user-cred button clicked, addMember
  $("#start-signup").click(function () {
    console.log("Ready to sign-up.");
    $("#signup-message").hide();
  });
  $("#submit-user-credentials").click(addMember);

  // // $("#start-signup").click(function () {
  // //   $("#signup-message").hide();
  // //   $("#submit-user-credentials").click(addMember);
  // // });

  $("#loginButton").click(loginMember);
  $("#logout").click(logoutMember);
});

function setCategory(){
  //Set the category to the text of the dropdown-item
  searchCategory = $(this).text();
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
    console.log("About to show photos");
    $('#artworkResults').append(showPhotos(results));
    console.log("Finished show photos");
    
    $('.commentSubmit').click(function () {
      if (getCookie("username") == ""){
        alert("Login or signup to make comments.");
      } else {
        commentPhoto(this); // maybe wrong
      }
    });
}

//Parses art data from c++. Appends all photos to photo gallery
function showPhotos(list){

  // Why is this suddenly broken?
  var artData = list.split('*'); //changed "" to ''

  //If there is nothing from c++ return "Internal Error"
  if (artData.length < 1) {
    return "<h3>Internal Error</h3>";
  } else {
    //var result = '<div class="row" style="padding-top: 70px;"><div class="col d-flex float-none"><div class="border rounded border-dark" style="width: 100%;">';
    var result="";
    var listLength = artData.length;
    console.log("Length of artData List: ");
    console.log(listLength);
    console.log("Appending Results: \n\n");

    for (var i = 6; i < listLength; i+=13){
      console.log(i);
      console.log("ArtData[i]: ");
      console.log(artData[i]);
      //Creates div
      result = '<div class="row" style="padding-top: 70px;"><div class="col d-flex float-none"><div class="border rounded border-dark" style="width: 100%;">';
      //Creates image
      result += '<img class="img-fluid lazyload" src=' + artData[i] + ' height="100%" align="left" style = "padding-top: 20px; padding-right: 10px; padding-bottom: 10px;">';
      //Creates description
      result += '<p style="padding-top: 20px;">Title: ' + artData[i-3] + '<br><br>Author: ' + artData[i-5] + ' ' + artData[i-4] + '<br>Location: ' + artData[i-1] + '<br>Date: ' + artData[i+5] + '<br>Technique: ' + artData[i-2] + '<br>School: ' + artData[i+3] + '<br>Type: ' + artData[i+2] + '<br>Form: ' + artData[i+1] + '</p>';
      //Creates like button
      result += '<button class="btn btn-warning text-center" type="button" style="margin-top: 0px;" id = "' + artData[i-6] + '">Like</button>';
      //Creates comment field and submit button
      // Input id is artId with C at the end
      result += '<form><div class="form-group"><input id="'+ artData[i-6] +'C" class="form-control" type="text" placeholder="comment here!" style="margin-top: 10px;"><button class="btn btn-light commentSubmit" id = "' + artData[i-6] + '" type="button" style="margin-bottom: 50px;margin-top: 10px;">submit</button>';
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
  $("#signup-message").hide();

  username = $('#signup-username').val();
  email = $('#signup-email').val();
  password1 = $('#signup-password').val();
  password2 = $('#signup-password-repeated').val();

  console.log(username);
  console.log(email);
  console.log(password1);
  console.log(password2);

  if (password1 === password2) { // strict equality with ===
    console.log("Sending info to server");
    $("#signup-message").hide();
    $.ajax({
      url: '/cgi-bin/'+ajaxUser+'_artAppAddMember.cgi?userName='+username+'&email='+email+'&password='+password1,
      dataType: 'text',
      success: isUsernameEmailAvailable, // cgi should return character T if username not taken; F otherwise
      error: function(){alert("Error: Something went wrong");}
    });

  } else {
    console.log("Passwords do not match");
    $("#signup-message").text("These passwords do not match.");
    $("#signup-message").show();
    //alert("Passwords do not match.");
  }
}

function closeModal(modalType){
  document.getElementById(modalType).setAttribute("style", "display: none");
  document.getElementById(modalType).setAttribute("class", "modal fade hide");
  document.getElementById(modalType).setAttribute("aria-modal", "false");
  document.getElementById(modalType).setAttribute("aria-hidden", "true");
  document.getElementsByTagName("BODY")[0].setAttribute("class", "");
  var bodyNode = document.getElementsByTagName("BODY")[0];
  bodyNode.removeChild(bodyNode.lastChild);

  //$("body").attr("class", "");
  //$("body").removeChild($("body").lastChild); // Removes div showing background fade
}

function openModal(modalType){
  document.getElementById(modalType).setAttribute("style", "display: block");
  document.getElementById(modalType).setAttribute("class", "modal fade show");
  document.getElementById(modalType).setAttribute("aria-modal", "true");
  document.getElementById(modalType).setAttribute("aria-hidden", "false");
  document.getElementsByTagName("BODY")[0].setAttribute("class", "modal-open");
  //$("body").attr("class", "modal-open");
  var node = document.createElement("DIV");
  node.setAttribute("class","modal-backdrop fade show");
  document.getElementsByTagName("BODY")[0].appendChild(node);
  //$("body").appendChild(node); // Adds div showing background fade
}

function isUsernameEmailAvailable(results){
  console.log("Results: " + results);
  var parsedResults = results.split(';'); // Hopefully works

  if (parsedResults[0] == ""){
    $("#signup-message").hide();
    console.log("Signup successful");
    // Close signup modal
    closeModal("signupModal");
    openModal("loginModal");

    // document.getElementById("signupModal").setAttribute("style", "display: none");
    // document.getElementById("signupModal").setAttribute("class", "modal fade hide");
    // document.getElementById("loginModal").setAttribute("style", "display: block");
    // document.getElementById("loginModal").setAttribute("class", "modal fade show");
    $("#loginClose").click(function () {
      console.log("Attempting to close login modal.");
      closeModal("loginModal");

      // document.getElementById("loginModal").setAttribute("style", "display: none");
      // document.getElementById("loginModal").setAttribute("class", "modal fade hide");
      // $("body").setAttribute("class",""); // Not sure if valid
      // $(".modal-backdrop").hide();
    });
  } else if (parsedResults.length == 1) {
    console.log(parsedResults[0] + " taken."); // Check index
    console.log("taken."); // Maybe delete??
    // Maybe we could have a message div in the signup/login modal
    // The message changes depending on the situation
    $("#signup-message").text("You cannot make an account with this " + parsedResults[0] + " because it is taken.");
    $("#signup-message").show();
    //alert("Email in use.");
  } else {
    console.log("Email and username taken.");
    $("#signup-message").text("You cannot make an account with this username or email because they are taken.");
    $("#signup-message").show();
  }
}

// Login member
function loginMember(){
  console.log("Clicked Log In");

  email = $('#login-email').val();
  password = $('#login-password').val();
  console.log(email);
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
  console.log("Result:", results);
  if (results == ""){
    console.log("Login unsuccessful :(");
    clearCookie(); // Clear username and memberId
    $("#invalid_login").show();
  } else {
    console.log("Login successful!");
    loggedInNavButtonView();
    console.log("Username before:", getCookie("username"));
    var parsedResults = results.split(' ');
    document.cookie = parsedResults[0]; // adds memberId cookie
    document.cookie = parsedResults[1]; // adds username cookie
    console.log("Username after:", getCookie("username"));

    // Close login modal
    closeModal("loginModal");
    // document.getElementById("loginModal").setAttribute("style", "display: none");
    // document.getElementById("loginModal").setAttribute("class", "modal fade hide");
    // $(".modal-backdrop").hide();
  }
  if (getCookie("username") == ""){
    console.log("No one logged in.");
  } else {
    // DO SOMETHING!!!
    alert("Welcome back " + getCookie("username") + "!");
    console.log(getCookie("memberId"));
    console.log(getCookie("username") + " is logged in!");
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

function setNavButtonView() {
  var username = getCookie("username");
  if (username != "") { // Someone logged in
    loggedInNavButtonView();
    console.log(username + " logged in.");
  } else {
    defaultNavButtonView();
    //$("#logout").hide();
    console.log("Default page");
  }
}

// Hide logout buttons; show login/signup
function defaultNavButtonView(){
  $("#invalid_login").hide(); // Maybe unnecessary
  $("#start-signup").show();
  $("#start-login").show();
  $("#logout").hide();
}

// Hide login/signup buttons; show logout
function loggedInNavButtonView(){
  $("#invalid_login").hide(); // Maybe unnecessary
  $("#start-signup").hide();
  $("#start-login").hide();
  $("#logout").show();
}

// Logout member
function logoutMember() {
  defaultNavButtonView();
  clearCookie();
  console.log("Logged out!");
}

function clearCookie() {
  document.cookie = "memberId=";
  document.cookie = "username=";
}

function commentPhoto(commentSubmitButton) {
  var memberId = getCookie("memberId");
  var artId;
  var comment;
  if (getCookie("username") == "") {
    alert("Please login to be able to comment on artwork.");
  } else {
    artId = $(commentSubmitButton).attr('ID');
    console.log(artId);
    comment = $("#" + artId + "C").val();
    console.log(comment);

    $.ajax({
      url: '/cgi-bin/'+ajaxUser+'_artAppCommentPhoto.cgi?artId=' + artId + '&comment=' + comment + '&commentOnType=artwork&memberId=' + memberId,
      dataType: 'text',
      success: commentSubmitted, // is emptyString necessary?
      error: function(){alert("Error: Could not comment on photo");}
    });
  }
}

// Maybe need space for results as input?
function commentSubmitted(results){
  console.log("Comment made!");
}

// Like photo
function likePhoto() {
  var username = getCookie("username");
  if (username != "") {
    alert("Please login to be able to like artwork.");
  } else {
    var artId = $(this).attr('ID');

    $.ajax({
      url: '/cgi-bin/'+ajaxUser+'_artAppLikePhoto.cgi?artId=' + artId,
      dataType: 'text',
      success: displayNumLikes,
      error: function(){alert("Error: Could not like photo");}
    });
  }
}

// What is this function supposed to do???
function displayNumLikes(results) {
  $(this).text() = results;
}

