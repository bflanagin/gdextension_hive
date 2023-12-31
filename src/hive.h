#ifndef HIVE_H
#define HIVE_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/http_client.hpp>
#include <godot_cpp/classes/http_request.hpp>
#include <godot_cpp/classes/crypto.hpp>
#include <godot_cpp/classes/crypto_key.hpp>

// Transaction headers for sending data to the chain.
#include "TX/signTransaction.h"
#include "TX/broadcastTransaction.h"
#include "TX/createTransaction.h"

// Receieve header for retrieveing and processing data from the chain.

//TBR

// Wallet headers for storing, retrieving and securing keys and other "owned" items from the chain

#include "wallet/wallet.h"
//using namespace hive_wallet;


namespace godot {

	class HIVE:public Node {
		GDCLASS(HIVE,Node)

		private:
			double time_passed;
			
			
		protected:
			static void _bind_methods();

		public:
			HIVE();
			~HIVE();

			void _process(double delta);
			int post(String data);
			int authenticate(String account, String key);
			void get_post_history(String account,int count);
			void get_post(String account,String url);
			
		};
	class HIVE_WALLET:public HIVE {
		GDCLASS(HIVE_WALLET,HIVE)

		private:
			double time_passed;
			double something;
			String private_posting_key = "posting";
			String private_active_key = "active";
			String private_memo_key = "memo";

		protected:
			static void _bind_methods();

		public:
			HIVE_WALLET();
			~HIVE_WALLET();

			void _process(double delta);
			
			String get_private_key(int type);
			bool set_private_key(int type,String key);
			String get_memos(String account,int count);
			String get_transfers(String account,int count);
			String get_wallet_info(String account);
		};
}

#endif
