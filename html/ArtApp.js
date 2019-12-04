var searchCategory;  //Category to be searched by: Title, Author ...

$(document).ready(function () {
  //When an item in the dropdown is clicked set the category
  console.log("ready!");
  $(".dropdown-item").click(setCategory);
  // getMatches when search button is clicked
  $(".action-button").click(getMatches);
  
  $(".dropdown-menu a").click(function(){
    console.log("pick!"+$(this).text());
    if ( $(this).hasClass("select-menu") ) {
      $(this).parents(".dropdown").find('.selection').text($(this).text());
      operation=$(this).text();
      console.log("Main-menu");
      changeOperation(operation);
    } /*else if ($(this).hasClass("add-item")) {
    $(this).parents(".dropdown").find('.selection').text($(this).text());
    console.log($(this).text());
    } else if ($(this).hasClass("edit-item")) {
    $(this).parents(".dropdown").find('.selection').text($(this).text());
    console.log($(this).text());
    }
    */
  });
  //trying to add dropdown js - again
  
  
  /*//testing comment begin - S Kim
  //dropdown menu
  $('.dropdown-menu a').click(function(){
    $('#selectedtype').text($(this).text());
  });
  *///testing comment end
  
  
  
  /*//testing comment begin - S Kim
  $(".dropdown-menu a").click(function(){
    console.log("pick!"+$(this).text());
    if ( $(this).hasClass("main-menu") ) {
      $(this).parents(".dropdown").find('.selection').text($(this).text());
      operation=$(this).text();
      console.log("Main-menu");
      changeOperation(operation);	    
    } else if ($(this).hasClass("add-item")) {
      $(this).parents(".dropdown").find('.selection').text($(this).text());
      console.log($(this).text());
    } else if ($(this).hasClass("edit-item")) {
      $(this).parents(".dropdown").find('.selection').text($(this).text());
      console.log($(this).text());
    } 	
  });
  *///testing comment end
//});
  // Outer layer of click event probably unnecessary
  $("#start-signup").click(function() {
    $("#submit-user-credentials").click(addMember);
  });
});

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
      url: '/cgi-bin/brydon1_artAppComplete.cgi?userName='+username+'&email='+email+'&password='+password1,
      dataType: 'text',
      success: isUsernameAvailable, // cgi should return character T if username not taken; F otherwise
      error: function(){alert("Error: Something went wrong");}
    });

  } else {
    alert("Passwords do not match."); // I think this is how you do this??
  }
}

function isUsernameAvailable(results){

  if (results == 'T'){
    console.log("Signup successful");
    alert("Signup successful."); // Maybe change to close modal
  } else {
    console.log("Signup failure.");
    alert("Username is not available.");
  }
}

//Switches to search page and displays the photos related to the user's search
function getMatches(){
    //Hides the search page and shows the homepage
    ajaxUser = brydon1;
    $('#home').hide();
    console.log("hide the homepage");
    $('#search').show();
    console.log("Show seach page");

    var searchTerm = $('#search-field2').val();

    //Sends search term and category to C++ then calls processResults
    $.ajax({
    	url: '/cgi-bin/'+ajaxUser+'_artAppComplete.cgi?searchVal='+searchTerm+'&searchCategory='+searchCategory,
    	dataType: 'text',
    	success: processResults,
    	error: function(){alert("Error: Could not search");}
    });
}

//Empties photo gallery (again?) builds new gallery using buildGallery function
function processResults(results) {
    //console.log("Results:"+results);
    $('.photo-gallery').empty();
    $('.photo-gallery').append(buildGallery(results));
}

//Parses art data from c++. Appends all photos to photo gallery
function buildGallery(list){

  var artData = list.split("*");

  //If there is nothing from c++ return "Internal Error"
  if (artData.length < 1) {
	  return "<h3>Internal Error</h3>";
  } else {

      var result = '<div class="container">';

      var listLength = artData.length;
      //console.log("Length of artData List: ");
      //console.log(listLength);
      //console.log("Appending Results: \n\n");
      for (var i = 7; i < listLength; i+=13){
    	  //console.log(i);
    	  //console.log("ArtData[i]: ");
    	  //console.log(artData[i]);
    	  result += '<div class="col-sm-6 col-md-4 col-lg-3 item"><a data-lightbox="photos" href=' + artData[i] + '><img class="img-fluid" src=' + artData[i] + '></a></div>'
      }
    result += "</div>";

    return result;
  }
}



//Login Function
//id's login-email login-password

//Signup Function
//id's signup-email signup-password signup-password-repeated
