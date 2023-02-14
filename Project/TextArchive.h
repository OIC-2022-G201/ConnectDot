#pragma once
#include "FrozenHelper.h"
#include "frozen.h"

namespace frozen {
	class TextOutputArchive : public frozen::OutputArchive<TextOutputArchive> {
	public:
		explicit TextOutputArchive(std::ostream& stream)
			: OutputArchive<TextOutputArchive>(this), its_writer_(stream) {}

		inline void SaveText(std::string data, std::streamsize size) {
			std::streamsize writtenSize = 0;
			its_writer_ << data<< " ";
		}

	private:
		std::ostream& its_writer_;
	};
	class TextInputArchive : public frozen::InputArchive<TextInputArchive> {
	public:
		explicit TextInputArchive(std::istream& stream)
			: InputArchive<TextInputArchive>(this), its_writer_(stream) {}
		template <class T>
		inline void LoadText(T& data, std::streamsize size) {
			std::string s;
			its_writer_ >> s;
			LoadType(data,s);
		}
		void LoadType(std::string& data, const std::string& str) const {
			data = str;
		}
		void LoadType(int& data, const std::string& str) const {
			data = std::stoi(str);
		}
		void LoadType(double& data, const std::string& str) const {
			data = std::stod(str);
		}
		void LoadType(float& data, const std::string& str) const {
			data = std::stof(str);
		}
		void LoadType(long& data, const std::string& str) const {
			data = std::stol(str);
		}
		void LoadType(long double& data, const std::string& str)const {
			data = std::stold(str);
		}
		void LoadType(long long& data, const std::string& str) const {
			data = std::stoll(str);
		}
		void LoadType(unsigned long& data, const std::string& str) const {
			data = std::stoul(str);
		}
		void LoadType(unsigned long long& data, const std::string& str)const {
			data = std::stoull(str);
		}

	private:
		std::istream& its_writer_;
	};
	template <class T>
		requires std::is_fundamental_v<T>
	inline void FROZEN_SAVE_FUNCTION_NAME(TextOutputArchive& ar, T const& t) {
		ar.SaveText(std::to_string(t), sizeof(t));
	}
	template <class T>
		requires std::is_fundamental_v<T>
	inline void FROZEN_SERIALIZE_FUNCTION_NAME(TextOutputArchive& ar,
		T const& t) {
		ar.SaveText(std::to_string(t), sizeof(t));
	}

	template <class T>
		requires std::is_fundamental_v<T>
	inline void FROZEN_LOAD_FUNCTION_NAME(TextInputArchive& ar, T& t) {
		ar.LoadText(t, sizeof(t));
	}
	template <class T>
		requires std::is_fundamental_v<T>
	inline void FROZEN_SERIALIZE_FUNCTION_NAME(TextInputArchive& ar, T& t) {
		ar.LoadText(t, sizeof(t));
	}

	//! Saving text data
	inline void FROZEN_SAVE_FUNCTION_NAME(TextOutputArchive& ar,
		std::string const& bd) {
		ar.SaveText(bd,bd.size());
	}

	//! Loading text data
	
	inline void FROZEN_LOAD_FUNCTION_NAME(TextInputArchive& ar,
		std::string& bd) {
		ar.LoadText(bd, bd.size());
	}
	template <class Archive, class T>
		requires std::is_same_v<Archive, TextOutputArchive> ||
	std::is_same_v<Archive, TextInputArchive>
		void FROZEN_SERIALIZE_FUNCTION_NAME(Archive & ar, SizeTag<T>&t) { ar(t.size_); }
}  // namespace frozen