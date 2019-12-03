var searchCategory;  //Category to be searched by: Title, Author ...

$(document).ready(function () {
  //When an item in the dropdown is clicked set the category
  $(".dropdown-item").click(setCategory);
  // getMatches when search button is clicked
  $(".action-button").click(getMatches);
  $("#submit-signup").click(addMember);
});

function setCategory(){
  //Set the category to the text of the dropdown-item
  searchCategory = $(this).text();
}

// Adds member to user table in SQL database if user does not already exist;
// Otherwise, shows error message

function addMember(){
  userName = $('#signup-email').val();
  password1 = $('#signup-password').val();
  password2 = $('#signup-password-repeated').val();
  if (password1 === password2) { // strict equality with ===

    $.ajax({
      url: '/cgi-bin/brydon1_artAppComplete.cgi?userName='+userName+'&password='+password1,
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
    alert("Signup successful."); // Maybe change to close modal
  } else {
    alert("Username is not available.");
  }
}

//Empties photo gallery and then fills with new images from our c++ file
//through the function processResults
function getMatches(){
    //$('.photo-gallery').empty();

    /*
    $('.page').hide();
    console.log("pick!"+$(this).attr('data-page'));
	$(this).parents(".dropdown").find('.selection').text($(this).text());
	$('#'+$(this).attr('data-page')).show();
    */

    $('#home').hide();
    console.log("hide the homepage");
    $('#search').show();
    //document.body.style.background = 'white';
    //$('#'+$(this).attr('search')).show();
    console.log("Show seach page");
    //what this *should* do: hide the home, display the search page

    $.ajax({
    	url: '/cgi-bin/brydon1_artAppComplete.cgi?searchVal='+$('#search-field').val(),
    	dataType: 'text',
    	success: processResults,
    	error: function(){alert("Error: Something went wrong");}
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
