

$(document).ready(function () {
  $(".action-button").click(getMatches);
  //search-field
});

function getMatches(){
    $('.photo-gallery').empty();
    $.ajax({
    	url: '/cgi-bin/brydon1_artAppComplete.cgi?find='+$('#searchfield').val(),
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
  var artDatum = list.split(",");

  if (artDatum.length < 1) {
	  return "<h3>Internal Error</h3>";
  } else if (artDatum.length == 1) {
	  return "<h3>Nothing Found</h3>";
  } else {

    }


}
