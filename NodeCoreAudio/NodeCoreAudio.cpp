//////////////////////////////////////////////////////////////////////////////
//
// NodeCoreAudio.cpp : Main module source, declares all exports
// 
//////////////////////////////////////////////////////////////////////////////

#include <v8.h>
using namespace v8;
//#pragma comment(lib, "node")
#include <node.h>

#include <string>
#include "AudioEngine.h"
#include <stdio.h>

/*
//Handle<Value> CreateEngine(const Arguments& info) 
NAN_METHOD(CreateEngine)
{
    //HandleScope scope;
    Nan::HandleScope scope;
    //return scope.Close( Audio::AudioEngine::NewInstance(info) );
    info.GetReturnValue().Set(Audio::AudioEngine::NewInstance(info));
} // end CreateEngine()
*/

void InitAll(Handle<Object> target) {
    Audio::AudioEngine::Init( target );

    Nan::SetMethod(target, "createAudioEngine", Audio::AudioEngine::NewInstance);
    //Nan::SetMethod(target, "createAudioEngine", CreateEngine);
    //target->Set( Nan::New<String>("createAudioEngine").ToLocalChecked(), CreateEngine);
    //target->Set( Nan::New<String>("createAudioEngine").ToLocalChecked(), Nan::New<FunctionTemplate>(CreateEngine)->GetFunction() );
    //target->Set( Nan::New<String>("createAudioEngine").ToLocalChecked(), Nan::New<FunctionTemplate>(Audio::AudioEngine::NewInstance)->GetFunction() );
    
    target->Set( Nan::New<String>("sampleFormatFloat32").ToLocalChecked(), Nan::New<Number>(1) );
    target->Set( Nan::New<String>("sampleFormatInt32").ToLocalChecked(), Nan::New<Number>(2) );
    target->Set( Nan::New<String>("sampleFormatInt24").ToLocalChecked(), Nan::New<Number>(4) );
    target->Set( Nan::New<String>("sampleFormatInt16").ToLocalChecked(), Nan::New<Number>(8) );
    target->Set( Nan::New<String>("sampleFormatInt8").ToLocalChecked(), Nan::New<Number>(10) );
    target->Set( Nan::New<String>("sampleFormatUInt8").ToLocalChecked(), Nan::New<Number>(20) );
}

NODE_MODULE( NodeCoreAudio, InitAll );
