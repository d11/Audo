#include "buffer.h"

#include <QDebug>


// Constructor
Buffer::Buffer(long f, int sR, QString n)
{
	qDebug() << "Initializing buffer with name '" << n << "'";
	frames = f;
	sampleRate = sR;
	name = n;
	data = new double[frames];
}

// Destructor
Buffer::~Buffer()
{ 
	qDebug() << "Freeing buffer '" << name << "'";
	delete[] data; 
}

//	Calculate the length of time the audio in this buffer lasts for
double Buffer::getTime() { 
	return (double)frames/(double)sampleRate; 
}

// Return the name that was assigned to the buffer
QString *Buffer::getName() { 
	return &name; 
}

//	Copy f frames from ptr into the buffer, if possible
void Buffer::copyData(long f, void *ptr) 
{
	try {
		if (f > frames) throw;
		memcpy(data, ptr, f);
	} 
	catch (...) {
		qDebug() << "Error: attempted to copy too many frames into a buffer!";
	}
}

void BuffNode::setPrev(BuffNode *ptr) { prev = ptr; }
void BuffNode::setNext(BuffNode *ptr) { next = ptr; }
BuffNode *BuffNode::getPrev() { return prev; }
BuffNode *BuffNode::getNext() { return next; }
