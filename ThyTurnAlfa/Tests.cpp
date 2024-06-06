//#include <iostream>
//
//#include "AI.hpp"
//#include "CSVWriter.hpp"
//#include "Random.hpp"
//#include "Reader.hpp"
//#include "SceneManager.hpp"
//#include "Stoper.hpp"
//
//int main() {
//    CsvWriter winners("winners9.csv");
//    CsvWriter times("times9.csv");
//
//    Reader reader;
//    if (!reader.readFile("appsettings.json")) {
//        return 1;
//    }
//    auto availibleCharacters = reader.extractCharacters();
//
//    int td1 = 5;
//
//    auto queue = Queue();
//    std::array<int, 4> a = { 0, 1, 2, -1 };
//
//    for (int k = 0; k < 500; k++) {
//        Player::count = 0;
//        std::array<std::unique_ptr<Player>, 2> b = {
//              std::make_unique<AI>(availibleCharacters, a, &td1, &queue),
//              std::make_unique<Random>(availibleCharacters, a)
//        };
//        queue = Queue(b);
//
//        for (const auto& player : b) {
//            for (auto& character : player->party) {
//                character.loadDmgEstimationTable(b);
//            }
//        }
//
//        int winner = -1;
//        std::cerr << "Test number: " << k << std::endl;
//        while (winner == -1) {
//            for (int i = 0; i < b.size(); i++) {
//                bool alive = false;
//                for (const Character& c : b.at(i)->party) {
//                    if (c.isAlive) {
//                        alive = true;
//                        break;
//                    }
//                }
//                if (!alive) {
//                    winner = b.at((i + 1) % b.size())->id;
//                    winners.writeRow({ std::to_string(k), std::to_string(winner) });
//                }
//            }
//
//            Character& character = queue.peek();
//            unsigned int id = character.getPlayerId();
//            auto it = std::find_if(b.begin(), b.end(), [&id](const auto& p) {
//                return p->id == id;
//            });
//
//            Stoper s;
//            s.start();
//            std::optional<Message> message = ((*it)->move(character, b));
//            s.end();
//            times.writeRow({ std::to_string(k), std::to_string(character.id), std::to_string(s.elapsed()) });
//
//            for (auto& player : b) {
//                for (auto& character : player->party) {
//                    character.applyEffects();
//                }
//            }
//        }
//    }
//    return 0;
//}