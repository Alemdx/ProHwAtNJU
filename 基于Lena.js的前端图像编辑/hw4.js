var imageLoader = document.getElementById('imageLoader');
var originalImage = document.getElementById("original-image");
var filteredImageCanvas = document.getElementById("filtered-image");
var filterChanger = document.getElementById("filter-changer");
var imageUploaded = false;

// Handle image upload into img tag
imageLoader.addEventListener('change', function(e){
		var reader = new FileReader();
    
    reader.onload = function(event){
        originalImage.onload = function(){
             console.log("Image Succesfully Loaded");
             imageUploaded = true;
        };
        originalImage.src = event.target.result;
    };
    
    reader.readAsDataURL(e.target.files[0]);   
}, false);

filterChanger.addEventListener("change", function(e){
	var filter = filterChanger.value;
  	
  if(imageUploaded && filter != "none"){
  
  	// Apply filter
  	LenaJS.filterImage(filteredImageCanvas, LenaJS[filter], originalImage);
  }
}, false);