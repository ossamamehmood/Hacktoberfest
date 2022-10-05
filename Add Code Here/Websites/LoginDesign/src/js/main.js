$(document).ready(function () {
    $('.switch').click(() => {
        if($('.signup_wrapper').hasClass('off')) {
            //SIGNUP
            $('.signup_wrapper').removeClass('off');
            $('.signup_wrapper').addClass('on');
            $('#signup_form .main_input').prop('disabled', false);

            //LOGIN
            $('.login_input').css('pointer-events', 'none');
            $('#login_form .main_input').prop('disabled', true);
        }else {
            //SIGNUP
            $('.signup_wrapper').removeClass('on');
            $('.signup_wrapper').addClass('off');
            $('#signup_form .main_input').prop('disabled', true);

            //LOGIN
            $('.login_input').css('pointer-events', '');
            $('#login_form .main_input').prop('disabled', false);
        }
    });
});