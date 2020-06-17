/*
 * Connor Patrick | connor<dot>patrick<at>chem<dot>ox<dot>ac<dot>uk
 * https://github.com/c-patrick/hlaweb
 */
(() => {
    const darkModeToggle = document.querySelector('dark-mode-toggle');
    const manifests = document.querySelectorAll('link[rel="manifest"]');
    const favicons = document.querySelectorAll('link[rel="icon"]');
    const themeColor = document.querySelector('meta[name="theme-color"]');
    const COLOR_SCHEME_CHANGE = 'colorschemechange';

    console.log(darkModeToggle.mode, "mode enabled!");
    if (darkModeToggle.mode === "light") {
        var data = '<a class="twitter-timeline" href="https://twitter.com/HLAGroupOx?ref_src=twsrc%5Etfw" data-chrome="nofooter noborders transparent" data-height="100%" data-theme="light">Tweets by HLAGroupOx</a>';
        $('twitter').html(data);
    } else if (darkModeToggle.mode === "dark") {
        var data = '<a class="twitter-timeline" href="https://twitter.com/HLAGroupOx?ref_src=twsrc%5Etfw" data-chrome="nofooter noborders transparent" data-height="100%" data-theme="dark">Tweets by HLAGroupOx</a>';
        $('twitter').html(data);
    } else {
        var data = '<a class="twitter-timeline" href="https://twitter.com/HLAGroupOx?ref_src=twsrc%5Etfw" data-chrome="nofooter noborders transparent" data-height="100%" data-theme="light">Tweets by HLAGroupOx</a>';
        $('twitter').html(data);
    }
  
    function reload() {
        location.reload();
    }
    darkModeToggle.addEventListener(COLOR_SCHEME_CHANGE, reload);
  })();