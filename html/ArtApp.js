

$(document).ready(function () {
  //getMatches when search button is clicked
  $(".action-button").click(getMatches);
});

//Empties photo gallery and then fills with new images from our c++ file
//through the function processResults
function getMatches(){
    $('.photo-gallery').empty();
    $.ajax({
    	url: '/cgi-bin/brydon1_artAppComplete.cgi?searchVal='+$('#search-field').val(),
    	dataType: 'text',
    	success: processResults,
    	error: function(){alert("Error: Something went wrong");}
    });
}

//Empties photo gallery (again?) builds new gallery using buildGallery function
function processResults(results) {
    console.log("Results:"+results);
    $('.photo-gallery').empty();
    $('.photo-gallery').append(buildGallery(results));
}

//Parses art data from c++. Appends all photos to photo gallery
function buildGallery(list){
  var artData = list.split("*^");

  //If there is nothing from c++ return "Internal Error"
  if (artData.length < 1) {
	  return "<h3>Internal Error</h3>";
  } else {

    //Creates container in lightbox
    var result = '<div class="container">';

    //Creates photos using the url from c++
    var listLength = artData.length;
    for (var i = 6; i < listLength; i+=13) {
      <div class="col-sm-6 col-md-4 col-lg-3 item"><a data-lightbox="photos" href=artData[i]><img class="img-fluid" src=artData[i]></a></div>
    }

    result += "</div>";

    return result;
  }
}
