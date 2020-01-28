// Things to add:
//    Delete account

var ajaxUser = "brydon1"; // Your username for ajax calls

$(document).ready(function() {
  // when submit-user-cred button clicked, addMember
  // $("#start-signup").click(function () {
  //   $("#signupModal-error-message").hide(); // Hide any previously added error message in signup modal
  // });

  // When user hits submit button in login modal, addMember function called
  $("#submit-user-credentials").click(tryAddMember);
  $("#loginButton").click(loginMember);
  $("#logout").click(logoutMember);
});

// Adds member to user table in SQL database if user does not already exist,
// and inputs are valid (email valid, passwords match)
// Otherwise, shows error message
function tryAddMember() {
  $("#signupModal-error-message").hide();

  username = $('#signup-username').val();
  email = $('#signup-email').val();
  password1 = $('#signup-password').val();
  password2 = $('#signup-password-repeated').val();

  if (password1 != password2) 
  { 
    $("#signupModal-error-message").text("These passwords do not match.");
    $("#signupModal-error-message").show();
  } 
  else if (!isValidPassword(password1)) 
  {
    $("#signupModal-error-message").text("Passwords must be at least 8 characters long.");
    $("#signupModal-error-message").show();
  } 
  else if (!isValidEmail(email)) 
  {
    if (charInString(';',email)) {
      $("#signupModal-error-message").text("Please enter a valid email without a semicolon.");
    } else {
      $("#signupModal-error-message").text("Please enter a valid email.");
    }
    $("#signupModal-error-message").show();
  } 
  else if (!isValidUsername(username)) 
  {
    if (charInString(';',username)) {
      $("#signupModal-error-message").text("Usernames cannot contain semicolons.");
    } else {
      $("#signupModal-error-message").text("Please enter a valid username.");
    }   
    $("#signupModal-error-message").show();
  } 
  else 
  {
    $("#signupModal-error-message").text(""); // clear error messages
    $("#signupModal-error-message").hide();
    $.ajax({
      url: '/cgi-bin/' + ajaxUser + '_artAppAddMember.cgi?userName=' + username + '&email=' + email + '&password=' + password1,
      dataType: 'text',
      success: isUsernameEmailAvailable, // cgi should return character T if username not taken; F otherwise
      error: function() {
        alert("Error: Something went wrong");
      }
    });
  } 
}







function isUsernameEmailAvailable(results){
  //console.log("Results: " + results);
  var parsedResults = results.split(';'); // Hopefully works

  if (parsedResults[0] == ""){
    $("#signup-error-message").hide();
    // Close signup modal
    closeModal("signupModal");
    openModal("loginModal");

    $("#loginClose").click(function () {
      closeModal("loginModal");
    });
  } else if (parsedResults.length == 1) {
    // Maybe we could have a message div in the signup/login modal
    // The message changes depending on the situation
    $("#signupModal-error-message").text("You cannot make an account with this " + parsedResults[0] + " because it is taken.");
    $("#signupModal-error-message").show();
  } else {
    $("#signupModal-error-message").text("You cannot make an account with this username or email because they are taken.");
    $("#signupModal-error-message").show();
  }
}

// Maybe add more restrictions
function isValidPassword(password){
  if (password.length < 8) {
    return false;
  }
  else {
    return true;
  }
}

function isValidEmail(email){
  if (charInString('@',email) && charInString('.',email) && !charInString(';',email)){
    return true;
  }
  return false;
}

function isValidUsername(username){
  if (username.length < 1){
    return true;
  }
  return false;
}

function charInString(char,string){
  var i = string.length;
  while (i--) {
    if (str.charAt(i) == char){
      return true;
    }
  }
  return false;
}

function closeModal(modalId){
  document.getElementById(modalId).setAttribute("style", "display: none");
  document.getElementById(modalId).setAttribute("class", "modal fade hide");
  document.getElementById(modalId).setAttribute("aria-modal", "false");
  document.getElementById(modalId).setAttribute("aria-hidden", "true");
  
  // NEW
  $("#" + modalId + "-error-message").hide();

  document.getElementsByTagName("BODY")[0].setAttribute("class", "");
  var bodyNode = document.getElementsByTagName("BODY")[0];
  bodyNode.removeChild(bodyNode.lastChild);
}

function openModal(modalId){
  document.getElementById(modalId).setAttribute("style", "display: block");
  document.getElementById(modalId).setAttribute("class", "modal fade show");
  document.getElementById(modalId).setAttribute("aria-modal", "true");
  document.getElementById(modalId).setAttribute("aria-hidden", "false");
  document.getElementsByTagName("BODY")[0].setAttribute("class", "modal-open");
  var node = document.createElement("DIV");
  node.setAttribute("class","modal-backdrop fade show");
  document.getElementsByTagName("BODY")[0].appendChild(node);
}





















// Login member
function loginMember() {
  email = $('#login-email').val();
  password = $('#login-password').val();

  if (email == "" || password == "") {
    alert("Invalid entry.");
  } else {
    //console.log("Sending info to server");
    $.ajax({
      url: '/cgi-bin/' + ajaxUser + '_artAppSigninMember.cgi?email=' + email + '&password=' + password,
      dataType: 'text',
      success: processLoginResults,
      error: function() {
        alert("Error: Something went wrong");
      }
    });
  }
}

// Process login results
function processLoginResults(results){
  //console.log("Result:", results);
  if (results == ""){
    //console.log("Login unsuccessful :(");
    clearCookie(); // Clear username and memberId
    $("#loginModal-error-message").show();
  } else {
    //console.log("Login successful!");
    loggedInNavButtonView();
    //console.log("Username before:", getCookie("username"));
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
    //console.log("No one logged in.");
  } else {
    // Do something!
    alert("Welcome back " + getCookie("username") + "!");
    //console.log(getCookie("memberId"));
    //console.log(getCookie("username") + " is logged in!");
  }
}

// Returns value assigned to cname in cookie
function getCookie(cname) {
  var name = cname + "=";
  var decodedCookie = decodeURIComponent(document.cookie);
  var ca = decodedCookie.split(';');
  for (var i = 0; i < ca.length; i++) {
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
    //console.log(username + " logged in.");
  } else {
    defaultNavButtonView();
    //$("#logout").hide();
    //console.log("Default page");
  }
}

// Hide logout buttons; show login/signup
function defaultNavButtonView(){
  $("#loginModal-error-message").hide(); // Maybe unnecessary
  $("#start-signup").show();
  $("#start-login").show();
  $("#logout").hide();
}

// Hide login/signup buttons; show logout
function loggedInNavButtonView(){
  $("#logout").show();
  $("#loginModal-error-message").hide(); // Maybe unnecessary
  $("#start-signup").hide();
  $("#start-login").hide();
}

// Logout member
function logoutMember() {
  defaultNavButtonView();
  clearCookie();
  //console.log("Logged out!");
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
    //console.log(artId);
    comment = $("#" + artId + "C").val();
    //console.log(comment);

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
  //console.log("Comment made!");
}

function getComments(commentViewButton) {
  //parseInt();

  var artId = $(commentViewButton).attr('NAME'); // Maybe will not work
  console.log("Sending artId:",artId); // I am guessing this is the problem?

  //comment = $("#" + artId + "C").val();
  //console.log(comment);

  $.ajax({
    url: '/cgi-bin/'+ajaxUser+'_artAppGetCommentsPhoto.cgi?artId=' + artId,
    dataType: 'text',
    success: processCommentResults, // is emptyString necessary?
    error: function(){alert("Error: Could not comment on photo");}
  });
}

function processCommentResults(results) {
    console.log("Results:",results);
    var commentInfoSplit = results.split("*");
    var artId = commentInfoSplit[0];
    console.log("ArtId:",artId);
    console.log("Results:",results);
    $('#' + artId + '_commentResults').empty(); // results[0] is artId
    console.log("About to show comments");
    $('#' + artId + '_commentResults').append(showComments(results));
    $('#' + artId + '_commentResults').show();

    console.log("Finished show comments");

    // Hide viewComments and show hideComments
    $('#' + artId + 'VC').hide();
    $('#' + artId + 'HC').show();
}

function showComments(comments){
  console.log("Parsing comments!");
  var commentInfoSplit = comments.split("*");
  var artId = commentInfoSplit[0];
  var displayComments = '';
  for (var i=1;i<(commentInfoSplit.length);i+=3){
    commentText = commentInfoSplit[i];
    console.log("Comment:",commentText);
    userId = commentInfoSplit[i+1];
    numLikes = commentInfoSplit[i+2];
    //displayComments += '<p>' + numLikes + ' ' + '<div class="arrow" id="' + artId + '_upVote" align="left"></div> ' + userId + ': ' + commentText + '</p>'
    //displayComments += '<p>' + numLikes + ' ' + userId + ': ' + commentText + '</p>'
    // No likes for now
    displayComments += '<p>' + userId + ': ' + commentText + '</p>'
  }
  console.log(displayComments);
  return displayComments;
}

// Like photo
function likePhoto() {
  console.log("Like Button clicked.");
  var username = getCookie("username");
  if (username == "") {
    alert("Please login to be able to like artwork.");
  } else {
    console.log("Username cookie exists");
    var artId = $(this).attr('ID');
    console.log("Got art ID." + artId);

    $.ajax({
      url: '/cgi-bin/'+ajaxUser+'_artAppLikePhoto.cgi?artId=' + artId,
      dataType: 'text',
      success: displayNumLikes,
      error: function(){alert("Error: Could not like photo");}
    });
    console.log("Ajax was called.");
  }
}

function displayNumLikes(results) {
  console.log("Results"+results);
  var likesAndId = results.split("*");
  var numLikes = likesAndId[0];
  var artId = likesAndId[1];

  console.log("ArtID:",artId);
  console.log("Likes:",numLikes);
  $("#"+artId).text(numLikes);
  console.log("Text of button should be changed.")
}