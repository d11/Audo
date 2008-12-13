#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <cstring>
#include <QString>

/*
 * An audio buffer handles storage and access of the actual audio data.
 */ 
class Buffer
{
	public:
		Buffer(long f, int sR, QString n);
		virtual ~Buffer();
		double getTime();
		QString *getName();
		void copyData(long f, void *ptr);

	private:
		QString name;
		long frames;
		int sampleRate;
		double *data;
};

/*
 * A section of audio is effectively made from a doubly-linked list
 * of audio buffers.
 */
class BuffNode : Buffer
{
	public:
		BuffNode(long f, int sR, QString n) : Buffer(f, sR, n) {};
		~BuffNode(){};
		void setPrev(BuffNode *ptr);
		void setNext(BuffNode *ptr);
		BuffNode *getPrev();
		BuffNode *getNext();

	private:
		BuffNode *prev;
		BuffNode *next;		
};


#endif /* _BUFFER_H_ */
