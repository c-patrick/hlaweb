# README

This is a work-in-progress site for the Harry Anderson research group website (http://hla.chem.ox.ac.uk). Most of the dynamic grids and rows are handled by **bootstrap**.

## Note

The sidebar and header are **server-side includes** and can be found in the `includes` folder.

`base.inc` is used to define a base URL and is used for testing.

## Image Slider
The `index.shtml` image slider uses W3.CSS to display a series of images, strongly based on the [W3Schools example](https://www.w3schools.com/w3css/w3css_slideshow.asp). A fade animation (`w3-animate-opacity`) is applied to each image in the slider. 

The slider displays the images at a fixed height as defined in `main.css`. The height responds to screen resolution using the `@media` rule for a given width range.

Images should be added to the slider following the general form:

    <img class="mySlides w3-animate-opacity" src="path/to/image" >

## Sidebar
### Recent News
The Recent News section is based on the Bootstrap grid system. Each new post is entered as a `row` class, and the picture and text are separated into columns.

Entries into the Recent News section should follow the general form:

    <div class="row">
    	<div class="col-4 col-12-small">
    		<a href="path/to/group/profile" class="image news"><img src="path/to/group/image" alt="" /></a>
    	</div>
    	<div class="col-8 col-12-small">
    		<p>#SOME_TEXT_HERE#.</p>
    	</div>
    </div>

To add two photos to the Recent News sidebar, the `image stack` class and a `column` class container should be used:

    <div class="row">
		<div class="col-4 col-12-small">
		    <div class="column">
			    <a href="path/to/group/profile_1" class="image stack"><img src="path/to/group/image_1" alt="" /></a>
			    <a href="path/to/group/profile_2" class="image stack"><img src="path/to/group/image_2" alt="" /></a>
		    </div>
		</div>
		<div class="col-8 col-12-small">
			<p>#SOME_TEXT_HERE#.</p>
		</div>
    </div>

Old items from Recent News should be moved to the Old News page `news.shtml`.

## Publications
Publication .shtml files are located under the `publications` folder. A new file should be created every 5 years to ensure the page remains a reasonable length.

### Pagination
A pagination bar for publications is located at the top and bottom of each page. A `pagination` class exists, making it simple to make changes to the pagination bar. The pagination class makes use of a list, where the first and last entries control the `Prev` and `Next` buttons. The remaining entries control navigation to the respective publication period.

To add a new page to the pagination bar, you must:

 1. Add a new list entry *after* the `Prev` button, of the following form

	    <li><a href="path/to/publication" class="page active">#NAME#</a></li>

 2. Set the `Prev` and `Next` buttons such that the `Next` button links to the previous publication period and the `Prev` button links to the next most recent one.
 3. If the page being added is the most recent, ensure the `Prev` button is disabled using the `button disabled` class. The same must also be done to the `Next` button if the page being added is positioned at the end of the pagination bar.

### Publication Entries
The publications are displayed using Bootstrap grids to ensure the page is responsive. Each `row` is split up into three columns: one containing the reference number, the second containing the reference and links, and the final containing the image.

The CSS selector `refdata` has been defined to assist with styling the reference, and is divided into multiple classes:
| Class | Entry |
|--|--|
| `authors` | is where the authors are to be entered following the convention of the chosen reference style |
| `journal` | is where the abbreviated journal should be entered. This class automatically italicises the content. A link to the journal should be entered here |
| `year` | is where the publication year should be entered. This class automatically bolds the content |
| `vol` | is where the journal volume should be entered |
| `page` | is where the page numbers should be entered. A link to the publication should be entered here |

When adding a reference, the following template should be used:

    <div class="ref">
    	<div class="col-1 col-12-small">
    		<h4 class="refdatanum">#NUMBER#</h4>
    	</div>
    	<div class="col-9 col-12-small">
    		<h3>#TITLE#</h3>
    		<p><refdata class="authors">#AUTHORS#.</refdata></p>
    		<p>
    		<refdata class="journal"><a "link/to/journal" ">#JOURNAL#</a></refdata>,
    		<refdata class="year">#YEAR#</refdata>,
    		<refdata class="vol">#VOLUME#</refdata>,
    		<refdata class="page"><a href="link/to/publication">#PAGES#</a></refdata>
    		</p>
    	</div>
    	<div class="col-2 col-12-small">
    		<span class="image pub"><img src="path/to/graphical/abstract" alt="" /></span>
    	</div>
    </div>

## Old News
News entries that have been removed from the Recent News sidebar should be moved into `news.shtml`. This page uses openers to separate news based on the year it was published. 

When adding news articles, make sure to put them in the correct opener. If one does not exist, simply create a new opener using the `opener` class. To improve the page layout, the most recent news articles are displayed by default - this can be set using the `opener active` class instead.

A new opener entry (that is open by default) would look like:

    <li> <span class="opener active">#YEAR#</span>
    	<ul>
    		<table>
    			<tr class="old_news">
    				<td class="date">#DATE#</td>
    				<td>#NEWS_STORY#.</td>
    			</tr>
    			
    			<--- more entries --->
    			
    		</table>
    	</ul>

## Photos
Photos are located on `photos.shtml`. This page uses a lightbox style from [blueimp-gallery](https://github.com/blueimp/Gallery) that displays the full image upon clicking the thumbnail. Integration with JQuery allows for images with the `data-gallery` attribute to be grouped into albums, depending on the value of the attribute.

Images are grouped by year using the `opener` class to reduce crowding on the page. Adding images follows these general steps:

 1. Ensure that the correct opener for the year exists (you may need to create a new one) with `<li> <span class="opener">2019</span>`
 2. Define a title for the album that will be displayed above each lightbox with `<li><a href="#">#TITLE#</a></li>`
 3. Create a new `<div>` element with a unique ID using only alphanumerical characters and avoiding spaces
 4. List each picture using the `<a>` element, defining paths to both the full-size image as well as the thumbnail.

**IMPORTANT:** Thumbnails should be resized such that the height is set to 200px.

As an example, the entry for a new opener with a new album may take the following form:

    <li> <span class="opener">#YEAR#</span>
    	<ul>
    		<li><a href="#">#NAME#</a></li>
    			<div id="#ID#">
    				<a href="path/to/full/image"
    		title="#TITLE#"
    		data-gallery="#blueimp-gallery-#ID#">
    				<img src="path/to/thumbnail" alt="#TITLE#" />
    				</a>
    				
    				<--- more entries --->
    				
    			</div>
    	</ul>
    </li>

## Alumni
The alumni page should be updated for all leaving members of the group. Members who have gone on to start their own academic group should be entered into the upper table, along with links to their research group website. An example entry would look like:

    <tr>
    	<td class="break"><a href="link/to/group/website" target="_blank">#NAME#</a></td>
    	<td>#POSITION#</td>
    	<td>#NEW_INSTITUTION#</td>
    </tr>

For all other ex-group members, the lower table should be used. An example entry into this table would look like:

    <tr>
    	<td class="break"><a href="link/to/group/profile">#NAME#</a></td>
    	<td>#POSITION#</td>
    	<td>#WHAT_THE_ARE_DOING#</td>
    </tr>

## Collaborators
The collaborators page consists of a table containing two columns: one listing the collaborator and the second listing their speciality and their institution.

When listing a collaborator, the corresponding country flag should be specified by `<span class="flag-icon flag-icon-XX">` where `XX` denotes the two-character country code ([ISO 3166-1 alpha-2](https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2)).

An example entry would look like:

    <tr class="collab">
    	<td><span class="flag-icon flag-icon-XX"></span> <a href="link/to/research/website">#NAME#</a></td>
    	<td>#AFFILIATION#</td>
    </tr>

## Vacancies
There is usually little that requires changing on this page. If, however, a vacancy in the group opens up then the vacancy can be listed. There are many ways of doing this, but in following the design language for the rest of the site, the `box` class could be used listing the vacancy. Also adding the `mb0` class removes any margin below the box to ensure it aligns with the twitter widget. An example entry for a PostDoc vacancy could look like:

    <div class="box mb0">
    	<p><strong>A postdoctoral positions is available in <a href="link/to/vacancy/page">#POSITION~</a>.</strong></p>
    	<ul class="actions fit">
    		<li><a href="link/to/vacancy/page" class="button primary">view</a></li>
    	</ul>
    </div>

An example entry is already included in `vacancies.shtml` and simply needs to be uncommented and updated with the desired information.
