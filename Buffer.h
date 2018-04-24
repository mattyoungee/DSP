#ifndef BUFFER_H
#define BUFFER_H

/*
	Shamelessly lifted from https://embeddedartistry.com/blog/2017/4/6/circular-buffers-in-cc
*/

typedef struct {
    uint32_t * buffer;
    size_t head;
    size_t tail;
    size_t size; //of the buffer
} RingBuffer;

int Buffer_Reset(RingBuffer * cbuf);
int Buffer_Put(RingBuffer * cbuf, uint32_t data);
int Buffer_Get(RingBuffer * cbuf, uint32_t * data);
bool Buffer_Empty(RingBuffer cbuf);
bool Buffer_Full(RingBuffer cbuf);

#endif