use std::os::raw::c_char;
use std::ffi::CStr;

#[no_mangle]
pub extern fn say(message: *const c_char) {
    let message = unsafe { CStr::from_ptr(message) };
    println!("{:?}", message);
}
