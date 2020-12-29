$(function() {


    $('.zakonczNaprawe').on("click", function() {
        // if (confirm("Wartość ID tego elementu to "+$(this).attr('id')))
        // {
        //  $.post("ajax_.php","c=Klasa&m=pokaz&id="+$(this).attr('id'),function(data){
        //    // wyswietalmy zwrotkę z wywolania AJAX
        //    $('div.mes').html(data).show();
        //  }); 
        // }
        // return false;
        alert("Wybrano " + $(this).text());
        //2 sposob
        $.ajax({
            url: 'ajax_.php',
            data: {c: 'RepairController', m: 'closeRepair', id: $(this).attr('id')},
            type: 'POST',
            dataType: 'html',
            success: function(data) {
                window.location.reload();
            }
        });

    });

    function asd(id) {

        alert("Wybrano " + id);
        //2 sposob
        $.ajax({
            url: 'ajax_.php',
            data: {c: 'RepairController', m: 'closeRepair', id: $(this).attr('id')},
            type: 'POST',
            dataType: 'html',
            success: function(data) {
                window.location.reload();
            }
        });

    }

    $(".datepicker").datepicker({
        showSecond: true,
        showMillisec: true,
        timeFormat: 'hh:mm:ss:l',
        dateFormat: 'yy-mm-dd',
        showOn: 'button',
        buttonImage: 'images/datepicker_ico.gif',
        duration: 'slow',
        buttonImageOnly: true,
        changeMonth: true,
        changeYear: true
    });
// jquery ui
    $("#accordion").accordion({
    });

    $("#tabs").tabs();


// getn checkbox value
    $('.btnGetSelectedValue').click(function() {
        var selectedArray = [];
        $(".cell input[type=checkbox]:checked").each(function() {
            selectedArray.push($(this).val());
        });
        alert(selectedArray);
    });
// context menu
    $('.op').on('click', function() {
        var top = 0;
        var left = 0;
        var id = "#" + this.id;

        var pos = $(id).position();
        top = pos.top + 10;
        left = pos.left + 10;

        $("#menu").css(
                {position: "absolute",
                    top: top + "px",
                    left: left + "px"
                }
        ).show();
    });

    $(".items li").not('.closeMenu').click(function() {
        //alert("Wybrano " + $(this).text());
        asd($(this).attr("id"));

        $('#menu').hide();
    });

    $(".closeMenu").click(function() {
        $('#menu').hide();
    });


// autotooltip

    var showTooltip = function(event) {
      var offsetX = 16;
      var offsetY = -32;
      var tooltipX = $(this).position.left - offsetX;
      var tooltipY = $(this).position.top - offsetY;
      var eventElement = event.target.id;
      //asd(eventElement);
      console.log(eventElement);
        
      //
//console.log('X '+tooltipX+' Y'+tooltipY);
      //console.log(event);
      $('.autotooltip', $(this)).css({top: tooltipY, left: tooltipX});
      $('.autotooltip', $(this)).show();
    };

    var hideTooltip = function(event) {
       $('.autotooltip', $(this)).hide();
    };

    $(document).ready(function(){
        $(".autotooltipcontainer .autotooltip-content").wrap("<div class='autotooltip'></div>");
        $(".autotooltipcontainer .autotooltip").hide();
        $(".autotooltipcontainer").bind({
            mouseover : showTooltip,
            mouseout : hideTooltip
        });
    });



//eof
});