
$(document).ready(function () {
  // getMatches when search button is clicked
  $(".action-button").click(getMatches);
});

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
    $('#'+$(this).attr('search')).show();
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
