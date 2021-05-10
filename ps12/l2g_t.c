// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#include <string.h>
#include "l2g_t.h"

static int __l2g_t_hash_computed;
static uint64_t __l2g_t_hash;

uint64_t __l2g_t_hash_recursive(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __l2g_t_get_hash)
            return 0;

    __lcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = __l2g_t_get_hash;
    (void) cp;

    uint64_t hash = (uint64_t)0xb9fad746b62a41afLL
         + __int64_t_hash_recursive(&cp)
         + __double_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __l2g_t_get_hash(void)
{
    if (!__l2g_t_hash_computed) {
        __l2g_t_hash = (int64_t)__l2g_t_hash_recursive(NULL);
        __l2g_t_hash_computed = 1;
    }

    return __l2g_t_hash;
}

int __l2g_t_encode_array(void *buf, int offset, int maxlen, const l2g_t *p, int elements)
{
    int pos = 0, element;
    int thislen;

    for (element = 0; element < elements; element++) {

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].utime), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_encode_array(buf, offset + pos, maxlen - pos, p[element].l2g, 3);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int l2g_t_encode(void *buf, int offset, int maxlen, const l2g_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __l2g_t_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __l2g_t_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __l2g_t_encoded_array_size(const l2g_t *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int64_t_encoded_array_size(&(p[element].utime), 1);

        size += __double_encoded_array_size(p[element].l2g, 3);

    }
    return size;
}

int l2g_t_encoded_size(const l2g_t *p)
{
    return 8 + __l2g_t_encoded_array_size(p, 1);
}

int __l2g_t_decode_array(const void *buf, int offset, int maxlen, l2g_t *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].utime), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __double_decode_array(buf, offset + pos, maxlen - pos, p[element].l2g, 3);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __l2g_t_decode_array_cleanup(l2g_t *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int64_t_decode_array_cleanup(&(p[element].utime), 1);

        __double_decode_array_cleanup(p[element].l2g, 3);

    }
    return 0;
}

int l2g_t_decode(const void *buf, int offset, int maxlen, l2g_t *p)
{
    int pos = 0, thislen;
    int64_t hash = __l2g_t_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __l2g_t_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int l2g_t_decode_cleanup(l2g_t *p)
{
    return __l2g_t_decode_array_cleanup(p, 1);
}

int __l2g_t_clone_array(const l2g_t *p, l2g_t *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int64_t_clone_array(&(p[element].utime), &(q[element].utime), 1);

        __double_clone_array(p[element].l2g, q[element].l2g, 3);

    }
    return 0;
}

l2g_t *l2g_t_copy(const l2g_t *p)
{
    l2g_t *q = (l2g_t*) malloc(sizeof(l2g_t));
    __l2g_t_clone_array(p, q, 1);
    return q;
}

void l2g_t_destroy(l2g_t *p)
{
    __l2g_t_decode_array_cleanup(p, 1);
    free(p);
}

int l2g_t_publish(lcm_t *lc, const char *channel, const l2g_t *p)
{
      int max_data_size = l2g_t_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = l2g_t_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = lcm_publish (lc, channel, buf, data_size);
      free (buf);
      return status;
}

struct _l2g_t_subscription_t {
    l2g_t_handler_t user_handler;
    void *userdata;
    lcm_subscription_t *lc_h;
};
static
void l2g_t_handler_stub (const lcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    l2g_t p;
    memset(&p, 0, sizeof(l2g_t));
    status = l2g_t_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding l2g_t!!!\n", status);
        return;
    }

    l2g_t_subscription_t *h = (l2g_t_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    l2g_t_decode_cleanup (&p);
}

l2g_t_subscription_t* l2g_t_subscribe (lcm_t *lcm,
                    const char *channel,
                    l2g_t_handler_t f, void *userdata)
{
    l2g_t_subscription_t *n = (l2g_t_subscription_t*)
                       malloc(sizeof(l2g_t_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->lc_h = lcm_subscribe (lcm, channel,
                                 l2g_t_handler_stub, n);
    if (n->lc_h == NULL) {
        fprintf (stderr,"couldn't reg l2g_t LCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int l2g_t_subscription_set_queue_capacity (l2g_t_subscription_t* subs,
                              int num_messages)
{
    return lcm_subscription_set_queue_capacity (subs->lc_h, num_messages);
}

int l2g_t_unsubscribe(lcm_t *lcm, l2g_t_subscription_t* hid)
{
    int status = lcm_unsubscribe (lcm, hid->lc_h);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe l2g_t_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}