This is a demo implementation for the paper:

   Domain Transform for Edge-Aware Image and Video Processing
   Eduardo S. L. Gastal  and  Manuel M. Oliveira
   ACM Transactions on Graphics. Volume 30 (2011), Number 4.
   Proceedings of SIGGRAPH 2011, (To Appear).

Usage of this demo is free for research purposes only. This software
is provided "as is" without any expressed or implied warranties of any
kind. The user also agrees that the authors shall not be liable for
any loss or damage of any sort incurred as the result of using this
software.

Refer to the publication above if you use this demo. For an up-to-date
version go to:

           http://inf.ufrgs.br/~eslgastal/DomainTransform


=== Introduction
================================================================================

This package contains executables which implement our normalized convolution
(NC) and recursive (RF) edge-preserving filters.

The "Windows" folder contains the executable and dll's required for
running our demo under Windows. It has been tested and should work under XP,
Vista and 7; 32 and 64-bit.

The "Linux_x64" folder contains the executable compiled under Ubuntu 10.04
64-bit.  It might work on other linux distributions, but this was not tested.
To download all the required dependencies under Ubuntu, use the following
command:

  sudo apt-get install libqt4-dev

Please note that the demo's graphical user interface has not been optimized for
displaying high-resolution images. 


=== Usage Guide
================================================================================

This is a small guide to test the quality and convergence of our domain
transform and edge-preserving filters:

1.  Run the domain_transform_filter.exe executable.

    - For the Linux version, make the file executable with the command
	  "chmod +x domain_transform_filter" (without quotes), and then run it
	  using "./domain_transform_filter".

2.  Select the statue.png image provided.

3.  A graphical user interface will appear alongside a window showing the
    result of filtering the selected image.

    - This interface allows control over the spatial and range standard
	  deviations of the kernel, as well as the number of iterations of our
	  two-pass 1D filter. The sliders are constrained to a fixed range;
	  however, the number boxes can be set to any valid value.

    - The "Display" option selects among our normalized convolution (NC) and
      recursive (RF) filters.

	- The "Zoom" option is provided to allow fitting higher resolution images
	  to the screen.

    - Feel free to use the "Load new image" button to test our filters using
      other images.

4.  Using the statue image, set the spatial sigma to 40, the range sigma to 0.8
    and the number of iterations to 1. Notice how vertical "stripes" are
    visible in the filtered image.

5.  Increase the number of iterations to 2. Notice how the stripes are reduced
    significantly, and are only noticeable with a careful inspection of the
    filtered image.

6.  Increase the number of iterations to 3. Notice how stripes are no longer
    visible.  The image has been smoothed and its edges preserved.


=== Changelog
================================================================================

May 2011 - Version 1.0: 
  - Initial release.
