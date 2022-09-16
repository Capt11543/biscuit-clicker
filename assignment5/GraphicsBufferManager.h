#pragma once

#include <GraphicsBuffer.h>
#include <GraphicsSystem.h>
#include <map>
#include <Trackable.h>

class GraphicsBufferManager: public Trackable {
	public:
		void addGraphicsBuffer(GraphicsBuffer* buffer, string name);
		void clear();
		GraphicsBuffer* getBackBuffer(GraphicsSystem* gSystem);
		GraphicsBuffer* getGraphicsBuffer(string name);
		GraphicsBufferManager();
		~GraphicsBufferManager();
	private:
		map<string, GraphicsBuffer*> mGraphicsBufferMap;
};