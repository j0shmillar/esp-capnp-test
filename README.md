

* Download clang based toolchain from https://github.com/espressif/llvm-project/releases/
* Extract toolchain and add its `bin` directory to your `PATH` environment variable
   ```bash
   export PATH=</path/to/distro>/esp-clang/bin:$PATH
   ```
* Set `IDF_TOOLCHAIN` environment variable:
   ```bash
   export IDF_TOOLCHAIN=clang
   ```
* Clean and build
   ```
   idf.py fullclean
   idf.py build
   ```

Note: In `esp/esp-idf/components/usb/hcd_dwc.c`, update lines 1096-1104 to:

```
bailout: 
{   
    struct pipe_obj *pipe = NULL;
    TAILQ_FOREACH(pipe, &port->pipes_idle_tailq, tailq_entry) {
        usb_dwc_hal_chan_set_ep_char(port->hal, pipe->chan_obj, &pipe->ep_char);
    }
}
exit:
    return ret;
```