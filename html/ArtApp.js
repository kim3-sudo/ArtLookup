

$(document).ready(function () {
  $(".action-button").click(getMatches);
  //search-field
});

function getMatches(){
    $('.photo-gallery').empty();
    $.ajax({
    	url: '/cgi-bin/brydon1_artAppComplete.cgi?searchVal='+$('#search-field').val(),
    	dataType: 'text',
    	success: processResults,
    	error: function(){alert("Error: Something went wrong");}
    });
}

function processResults(results) {
    console.log("Results:"+results);
    $('.photo-gallery').empty();
    $('.photo-gallery').append(buildGallery(results));
}

function buildGallery(list){
  var artData = list.split("*^");

  if (artData.length < 1) {
	  return "<h3>Internal Error</h3>";
  } else {

    var result = '<div class="container">';

    var listLength = artData.length;
    for (var i = 6; i < listLength; i+=13) {
      <div class="col-sm-6 col-md-4 col-lg-3 item"><a data-lightbox="photos" href=artData[i]><img class="img-fluid" src=artData[i]></a></div>
    }

    result += "</div>";

    return result;
  }
}
