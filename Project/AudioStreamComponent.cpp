﻿#include "AudioStreamComponent.h"

#include "ResourceContainer.h"
base_engine::AudioStreamComponent::AudioStreamComponent(Actor* owner): Component(owner)
{}

base_engine::AudioStreamComponent::~AudioStreamComponent()
{ Stop(); }

void base_engine::AudioStreamComponent::SetAudioBuffer(const MofSoundBufferPtr audio)
{ audio_buffer_ = audio; }

bool base_engine::AudioStreamComponent::AssetLoad(const std::string& name)
{
	audio_buffer_ =
		ResourceContainer::GetResource<ResourceContainer::SoundResourcePack,
		                               ResourceContainer::Sound>(name);
	return audio_buffer_ != nullptr;
}

void base_engine::AudioStreamComponent::Play() const
{ audio_buffer_->Play(); }

void base_engine::AudioStreamComponent::Stop() const
{ audio_buffer_->Stop(); }

void base_engine::AudioStreamComponent::Resume() const
{ audio_buffer_->Resume(); }

void base_engine::AudioStreamComponent::SetVolume(const float volume)
{ audio_buffer_->SetVolume(volume); }
