#include "ngx_http_gm_filter_convert.h"

ngx_int_t parse_convert_options(ngx_pool_t *p, ngx_array_t *args, ngx_uint_t start, convert_options_t *option_info)
{
    ngx_http_gm_command_t             *gm_cmd;
    ngx_http_gm_convert_option_t      *gm_option;
    ngx_str_t                         *gm_arg;

    ngx_uint_t                         i;
    ngx_str_t                         *value;
    ngx_array_t                       *options;

    value = args->elts;

    option_info->options = ngx_array_create(p, 1, sizeof(ngx_http_gm_convert_option_t));
    if (option_info->options == NULL) {
        return NGX_ERROR;
    }
    options = option_info->options;

    gm_option == NULL;
    for (i = 2; i < args->nelts; ++i) {
        if (ngx_strncmp(value[i].data, "-", 1) == 0) {
            gm_option = ngx_array_push(options);
            if (gm_option == NULL) {
                return NGX_ERROR;
            }

            if (ngx_strcmp(value[i].data, "-resize") == 0) {
                gm_option->type = NGX_HTTP_GM_RESIZE_OPTION;
            } else {
                return NGX_ERROR;
            }

            gm_option->args = ngx_array_create(p, 1, sizeof(ngx_str_t));
            if (gm_option->args == NULL) {
                return NGX_ERROR;
            }
        } else {
            if (gm_option == NULL) {
                return NGX_ERROR;
            }

            gm_arg = ngx_array_push(gm_option->args);
            if (gm_arg == NULL) {
                return NGX_ERROR;
            }

            gm_arg->data = value[i].data;
            gm_arg->len = value[i].len;
        }
    }

    return NGX_OK;
}


ngx_int_t convert_image(ngx_http_request_t *r, convert_options_t *option_info, Image *image)
{


    return NGX_OK;
}
