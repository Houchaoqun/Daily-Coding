
jQuery.noConflict();

jQuery(document).ready(function(){
	///// SHOW/HIDE USERDATA WHEN USERINFO IS CLICKED ///// 
	
	jQuery('.userinfo').click(function(){
		if(!jQuery(this).hasClass('active')) {
			jQuery('.userinfodrop').show();
			jQuery(this).addClass('active');
		} else {
			jQuery('.userinfodrop').hide();
			jQuery(this).removeClass('active');
		}
		//remove notification box if visible
		jQuery('.notification').removeClass('active');
		jQuery('.noticontent').remove();
		
		return false;
	});

	///// SHOW/HIDE VERTICAL SUB MENU /////	
	jQuery('.vernav > ul li a, .vernav2 > ul li a').each(function(){
		var url = jQuery(this).attr('href');
		jQuery(this).click(function(){
			if(jQuery(url).length > 0) {
				if(jQuery(url).is(':visible')) {
					if(!jQuery(this).parents('div').hasClass('menucoll') &&
					   !jQuery(this).parents('div').hasClass('menucoll2'))
							jQuery(url).slideUp();
				} else {
					jQuery('.vernav ul ul, .vernav2 ul ul').each(function(){
							jQuery(this).slideUp();
					});
					if(!jQuery(this).parents('div').hasClass('menucoll') &&
					   !jQuery(this).parents('div').hasClass('menucoll2'))
							jQuery(url).slideDown();
				}
				return false;	
			}
		});
	});
	
	
	///// SHOW/HIDE SUB MENU WHEN MENU COLLAPSED /////
	/// jquery中的live()方法在jquery1.9及以上的版本中已被废弃了，如果使用，会抛出TypeError: $(...).live is not a function错误。
	// jQuery('.menucoll > ul > li, .menucoll2 > ul > li').live('mouseenter mouseleave',function(e){
	// 	if(e.type == 'mouseenter') {
	// 		jQuery(this).addClass('hover');
	// 		jQuery(this).find('ul').show();	
	// 	} else {
	// 		jQuery(this).removeClass('hover').find('ul').hide();	
	// 	}
	// });
	// 
	
	jQuery('.menucoll > ul > li, .menucoll2 > ul > li').on('mouseenter mouseleave',function(e){
		if(e.type == 'mouseenter') {
			jQuery(this).addClass('hover');
			jQuery(this).find('ul').show();	
		} else {
			jQuery(this).removeClass('hover').find('ul').hide();	
		}
	});
	
	
	///// COLLAPSED/EXPAND LEFT MENU /////
	jQuery('.togglemenu').click(function(){
		if(!jQuery(this).hasClass('togglemenu_collapsed')) {
			
			//if(jQuery('.iconmenu').hasClass('vernav')) {
			if(jQuery('.vernav').length > 0) {
				if(jQuery('.vernav').hasClass('iconmenu')) {
					jQuery('body').addClass('withmenucoll');
					jQuery('.iconmenu').addClass('menucoll');
				} else {
					jQuery('body').addClass('withmenucoll');
					jQuery('.vernav').addClass('menucoll').find('ul').hide();
				}
			} else if(jQuery('.vernav2').length > 0) {
			//} else {
				jQuery('body').addClass('withmenucoll2');
				jQuery('.iconmenu').addClass('menucoll2');
			}
			
			jQuery(this).addClass('togglemenu_collapsed');
			
			jQuery('.iconmenu > ul > li > a').each(function(){
				var label = jQuery(this).text();
				jQuery('<li><span>'+label+'</span></li>')
					.insertBefore(jQuery(this).parent().find('ul li:first-child'));
			});
		} else {
			
			//if(jQuery('.iconmenu').hasClass('vernav')) {
			if(jQuery('.vernav').length > 0) {
				if(jQuery('.vernav').hasClass('iconmenu')) {
					jQuery('body').removeClass('withmenucoll');
					jQuery('.iconmenu').removeClass('menucoll');
				} else {
					jQuery('body').removeClass('withmenucoll');
					jQuery('.vernav').removeClass('menucoll').find('ul').show();
				}
			} else if(jQuery('.vernav2').length > 0) {	
			//} else {
				jQuery('body').removeClass('withmenucoll2');
				jQuery('.iconmenu').removeClass('menucoll2');
			}
			jQuery(this).removeClass('togglemenu_collapsed');	
			
			jQuery('.iconmenu ul ul li:first-child').remove();
		}
	});
	
});