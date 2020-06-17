<meta name="supported-color-schemes" content="dark light">
	    <meta name="color-scheme" content="dark light">
	    <meta name="theme-color" content="">

		<!-- Load dark mode toggle script from CDN -->
		<script type="module" src="https://unpkg.com/dark-mode-toggle"></script>

		<script>
    		// Self-invoked wrapper for scoping the `document` variable
		    !function( d ) {
				// Inject IE-specific scripts
		        if( !d.currentScript ){
					var head = document.getElementsByTagName('head')[0];

					var script = document.createElement('script');
					script.src = "https://unpkg.com/@babel/standalone/babel.min.js";
					head.appendChild(script);

					var script = document.createElement('script');
					script.type = 'text/babel';
					script.src = "/assets/js/colour-scheme-check.js";
					head.appendChild(script);

					var script = document.createElement('script');
					script.type = 'text/babel';
					script.src = "/assets/js/darkmode.js";
					head.appendChild(script);
		        } 
				// Inject scripts for modern browsers
				else {
					var head = document.getElementsByTagName('head')[0];

					var script = document.createElement('script');
					script.src = "/assets/js/colour-scheme-check.js";
					head.appendChild(script);

					var script = document.createElement('script');
					script.src = "/assets/js/darkmode.js";
					head.appendChild(script);
				}
		    }(document)
		</script>
		
		<!-- Add CSS variable support to IE -->
		<script>window.MSInputMethodContext && document.documentMode && document.write('<script src="/assets/js/ie11CustomProperties.js"><\x2fscript>');</script>

		<!-- Preload darkmode module to help reduce flash of incorrect theme on page load -->
		<link rel="modulepreload" href="https://unpkg.com/dark-mode-toggle" crossorigin>

		<!--
		  Conditionally either load the light or the dark stylesheet. The matching file will be downloaded with `highest`, the non-matching file with `lowest` priority. If the browser doesn't support `prefers-color-scheme`, the media query is unknown and the files are downloaded with `lowest` priority (but above I already force `highest` priority for my default light experience).
		-->
		<link rel="stylesheet" href="assets/css/light.css" media="screen and (prefers-color-scheme: light), (prefers-color-scheme: no-preference)">
		<link rel="stylesheet" href="assets/css/dark.css" media="screen and (prefers-color-scheme: dark)">
		<link rel="stylesheet" href="assets/css/main.css" />
