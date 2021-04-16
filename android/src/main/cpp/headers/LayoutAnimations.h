//
// Created by Szymon Kapala on 4/15/21.
//

#ifndef REANIMATEDEXAMPLE_LayoutAnimations_H
#define REANIMATEDEXAMPLE_LayoutAnimations_H
#include <fbjni/fbjni.h>
#include <jsi/jsi.h>
#include "JNIHelper.h"

namespace reanimated
{

using namespace facebook::jni;
using namespace facebook;

class LayoutAnimations : public jni::HybridClass<LayoutAnimations> {
 public:
  static auto constexpr kJavaDescriptor =
      "Lcom/swmansion/reanimated/layoutReanimation/LayoutAnimations;";
  static jni::local_ref<jhybriddata> initHybrid(
        jni::alias_ref<jhybridobject> jThis);
  static void registerNatives();

  void startAnimationForTag(int tag);
  void removeConfigForTag(int tag);
  jni::local_ref<JMap<JString, JObject>> getStyleWhileMounting(int tag, double progress, alias_ref<JMap<JString, JInteger>> values, int depth);
  jni::local_ref<JMap<JString, JObject>> getStyleWhileUnmounting(int tag, double progress, alias_ref<JMap<JString, JInteger>> values, int depth);

  void setWeakUIRuntime(std::weak_ptr<jsi::Runtime> wrt);

  void notifyAboutProgress(double progress, int tag);
  void notifyAboutEnd(int tag, int cancelled);

 private:
  friend HybridBase;
  jni::global_ref<LayoutAnimations::javaobject> javaPart_;
  std::weak_ptr<jsi::Runtime> weakUIRuntime;

  explicit LayoutAnimations(jni::alias_ref<LayoutAnimations::jhybridobject> jThis);
};

};
#endif //REANIMATEDEXAMPLE_LayoutAnimations_H