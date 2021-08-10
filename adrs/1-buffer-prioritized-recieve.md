# Use a buffer and prioritize *recieving* data in it

**Date**: 8/8/2021

## Problem

Lora senders only send once, unless you want to build retry logic. And that sounds painful. As such, I *really* want this device to prioritize recieving data so something isn't missed while the device is doing something else. As such...

## Requirements

- Use interrupts tied to the LoRa receiver. This will register that a packet was recieved and can be handled accordingly. It should be simple and quick.
- Get the data out of the recieve buffer as soon as resonable to free it up for more packets/interrupts. This will probably look like adding it to a processing/sending buffer of some kind.
- Send data out of that interim buffer as the system is able to.

## Implementation

This project already uses the Arduino TaskScheduler library. It has support for priority queues, callbacks, and immediate executions. IT should support the design above.
