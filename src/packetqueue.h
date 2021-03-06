/****************************************
 *
 * packetqueue.h
 * Declares a multithreaded AVPacket queue.
 *
 * This file is part of mattulizer.
 *
 * Copyright 2011 (c) Matthew Leach.
 *
 * Mattulizer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mattulizer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mattulizer.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <pthread.h>
extern "C"{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
}

class packetQueue
{
public:
	packetQueue();
	virtual ~packetQueue();
	void put(AVPacket* packet);
	int get(AVPacket* packetToReturn);

private:
	AVPacketList* first_packet;
	AVPacketList* last_packet;
	int num_packets;
	int size;
	pthread_mutex_t* mut;
};

