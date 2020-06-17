// If `prefers-color-scheme` is not supported, fall back to light mode.
// In this case, light.css will be downloaded with `highest` priority.
if (!window.matchMedia('(prefers-color-scheme)').matches) {
    document.documentElement.style.display = 'none';
	document.head.insertAdjacentHTML(
		'beforeend',
        '<link rel="stylesheet" href="assets/css/light.css" onload="document.documentElement.style.display = ``">'
    );
}